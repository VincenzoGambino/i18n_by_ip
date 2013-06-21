<?php

/*
* Callback for hook_language_negotiation_info().
*
* @see http://www.iso.org/iso/country_codes/iso_3166_code_lists/country_names_and_code_elements.htm
*/
function i18n_by_ip_detect_language() {
  $languages =  language_list('enabled');
  if (in_array($_SESSION['smart_ip']['location']['country_code'], $languages)) {
    return $_SESSION['smart_ip']['location']['country_code'];
  }
  else {
    return 'en';
  }
}