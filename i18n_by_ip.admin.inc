<?php

function i18n_by_ip_admin_settings_form() {
  
  dsm(variable_get('i18n_to_ip_service', 0));
  $ip_modules = array(
    'smart_ip' => t('Smart IP'),
  ); 
  $ip_modules_enabled = array();
  foreach ($ip_modules as $key => $value) {
   if (!module_exists($ip_modules[$key])) {
      $ip_modules_enabled[] = $key = $value;
   }
  } 
  dsm($ip_modules_enabled);
  $form = array();
  

  $form['i18n_to_ip_service'] = array (
    '#type' => 'radios',
    '#title' => t('Ip detection module'),
    '#options' => $ip_modules,
    '#default_value' => variable_get('i18n_to_ip_service', 0),
    '#description' => 'Select here your module.',
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
