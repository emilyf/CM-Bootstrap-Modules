<?php
  
function _cb_show_air_dates() {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // RETN uses node_reference field for airings.
    // VCAM uses entity_reference field for airings.
    // So we grab the field info first and do a switch
    // to account for both types of fields.
    $field_airing_show_ref = field_info_field('field_airing_show_ref');    
    //dpm($field_airing_show_ref);
    switch($field_airing_show_ref['type']) {
      case 'node_reference':
        $column = 'nid';
        break;
      case 'entity_reference':
        $column = 'target_id';
        break;
      case 'entityreference':
        $column = 'target_id';
        break;
    }
    $nid = arg(1);
    //dpm($nid);
    //
    $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'airing');
      $query->fieldCondition('field_airing_show_ref', $column, $nid, '=');
      $query->propertyCondition('created', strtotime('today UTC'), "<");
      $query->fieldOrderBy('field_airing_date', 'value', 'DESC');
      $query->range(0, 5);  
    $result = $query->execute();      
    if (isset($result['airing'])) {
      $aids = array_keys($result['airing']);
      $airings = entity_load('airing', $aids);
      foreach ($airings as $airing) { 
        $items[$airing->airing_id] = array(
          $airing,
        );
      }
      //dpm($items);
      // Send $items array to TPL.  
      return theme('cb_show_air_dates', 
        array (
          'content' => $items,
        )
      );
    }
  }
}
