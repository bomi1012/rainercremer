<?php 
error_reporting(E_ALL);
    //---- load classes
    define("SETTINGS", "settings/");
    define("CLASSES", "classes/");
    define("PART_PATH", "templates/partials/");
    define("INC_PATH", "templates/includes/");
    define("LAYOUT_PATH", "templates/layouts/");
    require_once SETTINGS . 'loader.inc';
    //----

        /**
     * LOCALHOST
     */
        define("PATH", "http://localhost/rainer/");
    
    /**
     * ONLINE  */
    //   define("PATH", "http://rainercremer.de/");
    
    
    $applicationContextManager = new ApplicationContextManager();
    $context = $applicationContextManager->getContext();
    $db = $applicationContextManager->getDB();
    $html = new HTMLElementsBuilder();
    $admin = AdministrationManager::getInstance();
    $team = new TeamSection($applicationContextManager);
    $services = new ServiceSection($applicationContextManager);
    $navi = new NavigationService($applicationContextManager);
    //----
    
    if ($context->getParamSubPage() == null) {
        define("BASE", "base/");
        define("CUSTOM", "custom/");
    } else {
        define("BASE", "../base/");
        define("CUSTOM", "../custom/");
    }
    
    
    define("CSS_B", BASE . "css/");
    define("JS_B", BASE . "js/");
    define("IMG_B", BASE . "images/");
    
    
    define("CSS", CUSTOM . "css/");
    define("JS", CUSTOM . "js/");
    define("IMG", CUSTOM . "images/");
     
    
    

    
    
   // define("SHOW_MENU", $pageBuilder->menuBuilder());
?>