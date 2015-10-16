<?php
/**
 * @file
 */

/**
 * Form constructor
 */
function site_cp_default_images_form($form, &$form_state) {  
  $content_types = array(
    'cm_show',
    'cm_project',
  );
  
  foreach($content_types as $content_type) {
    $form[$content_type] = array(
      '#type' => 'fieldset',
      '#title' => t($content_type),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      // Need to add this, otherwise form values will not be keyed by content type name.
      '#tree' => TRUE,
    );
    $form[$content_type]['content_type'] = array(
      '#type' => 'hidden',
      '#title' => t('Content Type'),
      '#size' => 5,
      '#default_value' => $content_type,
    );
    $form[$content_type]['default_image'] = array(
      '#type' => 'media',
      '#tree' => TRUE,
      '#title' => t($content_type . ': Default Image'),
      '#description' => t('Allowed file types: gif png jpg jpeg'),
      '#media_options' => array(
        'global' => array(
          'file_extensions' => 'gif png jpg jpeg',
          'max_filesize' => '3 MB',
          'types' => array('image'), 
        ),  
      ),  
      '#default_value' => array('fid' => site_cp_default_images_default_value($content_type)),
      //'#required' => TRUE,
    ); 
  } 
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  return $form;
}

/**
 * Form submit
 */
function site_cp_default_images_form_submit($form, &$form_state) {  
  //dpm($form_state);
  
  // Show
  $show_data = array(
    'content_type' => 'cm_show',
    'fid' => $form_state['values']['cm_show']['default_image']['fid'],
  );
  // Check if the record exists, to determine if it's a new record or an update.
  $update_record = db_query('SELECT content_type FROM {site_cp_default_images} WHERE content_type = :content_type', 
    array(
      ':content_type' => $show_data['content_type'],
    ))->fetchField();
  // Update record.
  if ($update_record) {
    drupal_write_record('site_cp_default_images', $show_data, array('content_type'));
  } 
  // Create new record.
  else {
    drupal_write_record('site_cp_default_images', $show_data);
  }
  
  // Series
  $series_data = array(
    'content_type' => 'cm_project',
    'fid' => $form_state['values']['cm_project']['default_image']['fid'],
  );
  // Check if the record exists, to determine if it's a new record or an update.
  $update_record = db_query('SELECT content_type FROM {site_cp_default_images} WHERE content_type = :content_type', 
    array(
      ':content_type' => $series_data['content_type'],
    ))->fetchField();
  // Update record.
  if ($update_record) {
    drupal_write_record('site_cp_default_images', $series_data, array('content_type'));
  } 
  // Create new record.
  else {
    drupal_write_record('site_cp_default_images', $series_data);
  }

}


/**
 * Helper function to get default values for form.
 */
function site_cp_default_images_default_value($content_type) {  
  $default_value = db_query('SELECT fid FROM {site_cp_default_images} WHERE content_type = :content_type', 
    array(
      ':content_type' => $content_type,
    ))->fetchField(); 
    
  return $default_value;
}
