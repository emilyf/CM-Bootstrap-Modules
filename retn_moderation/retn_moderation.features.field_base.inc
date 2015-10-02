<?php
/**
 * @file
 * retn_moderation.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function retn_moderation_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_moderation_content'
  $field_bases['field_moderation_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_moderation_content',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Needs Review',
        2 => 'Approved',
        3 => 'Declined',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
