<?php
/**
 * @file
 *   commerce_funds.rules.inc
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_store_funds_rules_action_info() {
  $actions = array();

  $actions['commerce_store_funds_credit'] = array(
    'label' => t('Credit store account balance'),
    'parameter' => array(
      'store' => array(
        'type' => 'commerce_store',
        'label' => t('Store'),
      ),
      'amount' => array(
        'type' => 'commerce_price',
        'label' => t('Amount'),
      ),
    ),
    'group' => t('Commerce Store Funds'),
    'callbacks' => array(
      'execute' => 'commerce_store_funds_credit',
    ),
  );

  $actions['commerce_store_funds_debit'] = array(
    'label' => t('Debit store account balance'),
    'parameter' => array(
      'store' => array(
        'type' => 'commerce_store',
        'label' => t('Store'),
      ),
      'amount' => array(
        'type' => 'commerce_price',
        'label' => t('Amount'),
      ),
    ),
    'group' => t('Commerce Store Funds'),
    'callbacks' => array(
      'execute' => 'commerce_store_funds_debit',
    ),
  );

  return $actions;
}
