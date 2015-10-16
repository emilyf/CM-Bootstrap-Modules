<?php
  
function _cb_show_chapters() {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // Need to check if this field exists / is attached to cm_show nodes,
    // RETN does not use this field.
    if (field_info_instance('node', 'field_video_chapters', 'cm_show')) {
      $cue_points = FALSE;
      $node = node_load(arg(1)); 
      //dpm($node); 
      if (isset($node->field_show_vod['und'])) {
        $field_show_vod_fid = $node->field_show_vod['und'][0]['fid'];
        // Get chapters data
        $result = db_query("SELECT * FROM {field_data_video_chapters} WHERE entity_id = :entity_id", array(':entity_id' => $field_show_vod_fid))->fetchAll();
        foreach($result as $item) {
          $items[] = $item;
        }
      }
    }
    // For RETN type site that uses cue_points
    else {
      $cue_points = TRUE;
      $node = menu_get_object();
      if ($node) {
        $field_show_vod_fid = $node->field_show_vod['und'][0]['fid'];
        $result = db_query("SELECT * FROM {field_data_cue_points} WHERE entity_id = :entity_id", array(':entity_id' => $field_show_vod_fid))->fetchAll();
        foreach($result as $item) {
          $fc_items = entity_load('field_collection_item', array($item->cue_points_value));
          foreach($fc_items as $fc_item) {
            //dpm($fc_item);
            $items[] = array(
              'nid' => $node->nid,
              'fid' => $field_show_vod_fid,
              'start' => $fc_item->cue_field_start['und'][0]['value'],
              'title' => $fc_item->cue_field_title['und'][0]['value'],
            );
          }
        }
      }
    }
    
    //dpm($items);

    if (isset($items)) {
      if ($cue_points) {
        // Send $items array to TPL.  
        return theme('cb_show_cue_points', 
          array (
            'content' => $items,
          )
        );
      }
      else {
        // Send $items array to TPL.  
        return theme('cb_show_chapters', 
          array (
            'content' => $items,
          )
        );
      }
    }
  }
}
