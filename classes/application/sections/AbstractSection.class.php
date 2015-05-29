<?php

abstract class AbstractSection {

    const ID = "id";
    const CONTENT = "content";


    protected $_application;
    protected $_html;
    
    public function __construct($application) {
        $this->_application = $application;
        $this->_html = new HTMLElementsBuilder();
    }
    
    public function merge($id, $array) {        
        $this->_application->getDB()->update($id, Util::serialize64($array), "sections");
    }
}

?>
