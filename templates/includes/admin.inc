<?php
if ($admin->isAdmin() === FALSE) {
    Util::refreschToPage(AdministrationManager::KEY_ROLE_ADMIN ."/".AdministrationManager::PAGE_LOGIN);
} else {
    include_once INC_PATH . 'admin_content.inc';
}
?>