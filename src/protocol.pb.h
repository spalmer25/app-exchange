/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.4 at Wed Dec 04 15:40:55 2019. */

#ifndef PB_LEDGER_SWAP_PROTOCOL_PB_H_INCLUDED
#define PB_LEDGER_SWAP_PROTOCOL_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(16) ledger_swap_NewTransactionResponse_amount_to_provider_t;
typedef PB_BYTES_ARRAY_T(16) ledger_swap_NewTransactionResponse_amount_to_wallet_t;
typedef struct _ledger_swap_NewTransactionResponse {
    char payin_address[50];
    char payin_extra_id[10];
    char refund_address[50];
    char refund_extra_id[10];
    char payout_address[50];
    char payout_extra_id[10];
    char currency_from[10];
    char currency_to[10];
    ledger_swap_NewTransactionResponse_amount_to_provider_t amount_to_provider;
    ledger_swap_NewTransactionResponse_amount_to_wallet_t amount_to_wallet;
    char device_transaction_id[10];
/* @@protoc_insertion_point(struct:ledger_swap_NewTransactionResponse) */
} ledger_swap_NewTransactionResponse;

/* Default values for struct fields */

/* Initializer values for message structs */
#define ledger_swap_NewTransactionResponse_init_default {"", "", "", "", "", "", "", "", {0, {0}}, {0, {0}}, ""}
#define ledger_swap_NewTransactionResponse_init_zero {"", "", "", "", "", "", "", "", {0, {0}}, {0, {0}}, ""}

/* Field tags (for use in manual encoding/decoding) */
#define ledger_swap_NewTransactionResponse_payin_address_tag 1
#define ledger_swap_NewTransactionResponse_payin_extra_id_tag 2
#define ledger_swap_NewTransactionResponse_refund_address_tag 3
#define ledger_swap_NewTransactionResponse_refund_extra_id_tag 4
#define ledger_swap_NewTransactionResponse_payout_address_tag 5
#define ledger_swap_NewTransactionResponse_payout_extra_id_tag 6
#define ledger_swap_NewTransactionResponse_currency_from_tag 7
#define ledger_swap_NewTransactionResponse_currency_to_tag 8
#define ledger_swap_NewTransactionResponse_amount_to_provider_tag 9
#define ledger_swap_NewTransactionResponse_amount_to_wallet_tag 10
#define ledger_swap_NewTransactionResponse_device_transaction_id_tag 11

/* Struct field encoding specification for nanopb */
extern const pb_field_t ledger_swap_NewTransactionResponse_fields[12];

/* Maximum encoded size of messages (where known) */
#define ledger_swap_NewTransactionResponse_size  264

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define PROTOCOL_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
