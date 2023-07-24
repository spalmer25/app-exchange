import pytest
from time import sleep
from ragger.backend import RaisePolicy
from ragger.utils import pack_APDU, RAPDU
from ragger.error import ExceptionRAPDU

from .apps.exchange import ExchangeClient, Rate, SubCommand
from .apps.ethereum import EthereumClient, ERR_SILENT_MODE_CHECK_FAILED

from .signing_authority import SigningAuthority, LEDGER_SIGNER


def prepare_exchange(backend, firmware, exchange_navigation_helper, amount: str):
    ex = ExchangeClient(backend, Rate.FIXED, SubCommand.SWAP)
    partner = SigningAuthority(curve=ex.partner_curve, name="Default name")

    ex.init_transaction()
    ex.set_partner_key(partner.credentials)
    ex.check_partner_key(LEDGER_SIGNER.sign(partner.credentials))

    tx_infos = {
        "payin_address": b"0xd692Cb1346262F584D17B4B470954501f6715a82",
        "payin_extra_id": b"",
        "refund_address": b"0xDad77910DbDFdE764fC21FCD4E74D71bBACA6D8D",
        "refund_extra_id": b"",
        "payout_address": b"bc1qer57ma0fzhqys2cmydhuj9cprf9eg0nw922a8j",
        "payout_extra_id": b"",
        "currency_from": "BSC",
        "currency_to": "BTC",
        "amount_to_provider": bytes.fromhex(amount),
        "amount_to_wallet": b"\x0b\xeb\xc2\x00",
    }
    fees = bytes.fromhex("0216c86b20c000") # ETH 0.000588

    ex.process_transaction(tx_infos, fees)
    ex.check_transaction_signature(partner)
    with ex.check_address(payout_signer=LEDGER_SIGNER, refund_signer=LEDGER_SIGNER):
        exchange_navigation_helper.simple_accept()
    ex.start_signing_transaction()


def test_swap_bsc_to_btc(backend, firmware, exchange_navigation_helper):
    amount       = '013fc3a717fb5000'
    wrong_amount = '013fc3a6be932100'
    prepare_exchange(backend, firmware, exchange_navigation_helper, amount)
    eth = EthereumClient(backend, derivation_path=bytes.fromhex("058000002c8000003c800000000000000000000000"))
    eth.get_public_key()

    # TODO add bsc signing
