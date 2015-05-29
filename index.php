<?php ob_start();
require 'settings/config.inc'; ?>
<!DOCTYPE html>
<?php
if ($applicationContextManager->isLoginPage() === TRUE) {
    include_once LAYOUT_PATH . 'login.tpl';
} else if ($admin->isAdmin()) {
    include_once LAYOUT_PATH . 'admin.tpl';
} else {
    include_once LAYOUT_PATH . 'default.tpl';
}
?>

