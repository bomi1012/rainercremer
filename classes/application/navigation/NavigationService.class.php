<?php

class NavigationService {
    /**
     * @var ApplicationContextModel 
     */
    private $_context;
    
    private $_navigationElements = array();
    public function getNavigationElements() { return $this->_navigationElements; }
    
    public function __construct($applicationContext) {
        $this->_context = $applicationContext->getContext();
        $this->initNavigationElements();
    }
    
    private function initNavigationElements() {
        $header = "header";
        $about = "content-about";
        $team ="content-team";
        $service = "content-service";
        $contact = "content-contact";
        
        $index_path = "#";
        $service_path = PATH . "service";
        
        if ($this->_context->getParamPage() == "service") {
            $index_path = PATH;
            $service_path = "#";
        }
        
        $this->_navigationElements[0] = new NavigationModel($this->createPath($index_path, $header), $header, IConsts::MENU_HOME);//TODO
        $this->_navigationElements[1] = new NavigationModel($this->createPath($index_path, $about), $about, IConsts::MENU_ABOUT);
        $this->_navigationElements[2] = new NavigationModel($this->createPath($index_path, $team), $team, IConsts::MENU_TEAM);
       // $this->_navigationElements[3] = new NavigationModel($this->createAdress($service_path, $service), $service, IConsts::MENU_SERVICES);
        $this->_navigationElements[4] = new NavigationModel($this->createPath($index_path, $contact), $contact, IConsts::MENU_CONTACT);

    }
    
    private function createPath($path, $router) {
        if ($path == "#") {
            return $path;
        } else {
            return $path . "#" . $router;
        }
    }
    
    /**
     * @return String fertige Menü
     */
    public function buildNavigationMenu() {        
        $menuString = "<ul class='one-page-menu'>";
        foreach ($this->_navigationElements as $value) {
            $menuString .= "<li>";
            $menuString .= "<a href='" . $value->getHref() . "' data-href='#" . $value->getData_href() . "'>";
            $menuString .= "<div>" . $value->getText() . "</div>"; 
            $menuString .= "</a>";            
            $menuString .= "</li>";
        }        
        $menuString .= "</ul>";
        return $menuString;
    }
}

?>
