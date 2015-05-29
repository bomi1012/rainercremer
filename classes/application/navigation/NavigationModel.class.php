<?php

class NavigationModel {
    
    private $_href;
    public function getHref() { return $this->_href; }
    
    private $_data_href;
    public function getData_href() { return $this->_data_href; }
    
    private $_text; 
    public function getText() { return $this->_text; }
    
    public function __construct($href, $dataHref, $text) {
        $this->_href = $href;
        $this->_data_href = $dataHref;
        $this->_text = $text;
    }
}

?>
