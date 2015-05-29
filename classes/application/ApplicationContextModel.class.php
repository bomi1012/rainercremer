<?php
class ApplicationContextModel {
    
    private $_id;
    public function get_id() { return $this->_id;   }
    public function set_id($_id) { $this->_id = $_id; }
        
    private $_paramPage;    
    public function getParamPage() { return $this->_paramPage;  }
    public function setParamPage($paramPage) {  $this->_paramPage = $paramPage;  }

    private $_paramSubPage;
    public function getParamSubPage() { return $this->_paramSubPage;  }
    public function setParamSubPage($paramSubPage) { $this->_paramSubPage = $paramSubPage;  }
    
    private $_title;
    public function getTitle() { return $this->_title;   }
    public function setTitle($title) { $this->_title = $title; }

    private $_pathInlude;
    public function getPathInlude() {  return $this->_pathInlude; }
    public function setPathInlude($pathInlude) {  $this->_pathInlude = $pathInlude; }
            
    public function __construct($param = null) {  }
}

?>
