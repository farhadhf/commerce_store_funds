<?php
/**
 * @file
 *   commerce_funds.views.inc
 */

/**
 * Impliments hook_views_data().
 */
function commerce_funds_views_data() {
  $data = array();

  $data['commerce_store_funds_account']['table'] = array(
    'group' => t("Commerce Store Funds"),
    'title' => t("Store Account"),
    'help' => t(""),
  );

  $data['commerce_store_funds_account']['table']['base'] = array(
    'field' => 'account_id',
    'title' => 'Commerce Store Funds Account',
    'help' => t(""),
    'weight' => 10,
  );

  $data['commerce_store_funds_account']['table']['join']['eck_commerce_store'] = array(
    'left_field' => 'store_id',
    'field' => 'id',
  );

  $data['commerce_store_funds_account']['account_id'] = array(
    'title' => t('Store Funds Account'),
    'help' => t('The Store Funds Account ID.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Expose the account store id.
  $data['commerce_store_funds_account']['store_id'] = array(
    'title' => t('Store'),
    'help' => t("The account's store ID."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'name',
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Account'),
      'help' => t("Relate this funds account to the store"),
      'handler' => 'views_handler_relationship',
      'base' => 'eck_commerce_store',
      'base field' => 'store_id',
      'field' => 'id',
      'label' => t('Commerce store funds account'),
    ),
  );

  // Expose the account balance.
  $data['commerce_store_funds_account']['balance'] = array(
    'title' => t('Balance'),
    'help' => t('The balance of the account.'),
    'field' => array(
      'handler' => 'commerce_payment_handler_field_amount',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Expose the account currency.
  $data['commerce_store_funds_account']['currency_code'] = array(
    'title' => t('Currency'),
    'help' => t('The currency of the account.'),
    'field' => array(
      'handler' => 'commerce_payment_handler_field_currency_code',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'commerce_payment_handler_filter_currency_code',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_store_funds_transaction']['table'] = array(
    'group' => t("Commerce Store Funds"),
    'title' => t("Transactions"),
    'help' => t(""),
  );
  $data['commerce_store_funds_transaction']['table']['base'] = array(
    'field' => 'transaction_id',
    'title' => 'Funds Transactions',
    'help' => t(""),
    'weight' => 10,
  );

  $data['commerce_store_funds_transaction']['uid'] = array(
    'title' => t('User Uid'),
    'help' => t('The uid of the transaction originator.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name',
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Transaction'),
      'help' => t("Relate this funds transaction to the user account"),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'field' => 'uid',
      'label' => t('User commerce funds transaction'),
    ),
  );

  $data['commerce_store_funds_transaction']['account_id'] = array(
    'title' => t('Store Funds Account'),
    'help' => t('The Store Funds Account ID.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Transaction'),
      'help' => t("Relate this funds transaction to the funds account"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_store_funds_account',
      'base field' => 'account_id',
      'field' => 'account_id',
      'label' => t('Store Funds account transaction'),
    ),
  );

  $data['commerce_store_funds_transaction']['reference'] = array(
    'title' => t('Special Reference data'),
    'help' => t('In case of a transfer transaction this field will hold the user id of the destination user, same for escrow payment transactions.'),
    'relationship' => array(
      'base' => 'eck_commerce_store',
      'field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('User Reference'),
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_store_funds_transaction']['created'] = array(
    'title' => t('Created On'),
    'help' => t('Time of creation.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_store_funds_transaction']['amount'] = array(
    'title' => t('Transaction Amount'),
    'help' => t('The transaction amount.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Expose the account currency.
  $data['commerce_store_funds_transaction']['currency_code'] = array(
    'title' => t('Currency'),
    'help' => t('The currency of the transaction.'),
    'field' => array(
      'handler' => 'commerce_payment_handler_field_currency_code',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'commerce_payment_handler_filter_currency_code',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_store_funds_transaction']['type'] = array(
    'title' => t('Transaction Type'),
    'help' => t('The transaction type.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'commerce_funds_type_views_handler_filter_in_operator',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_store_funds_transaction']['notes'] = array(
    'title' => t('Notes'),
    'help' => t('Comments.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
