<?php
class DB extends PDO {

    private static $_instance;
    private $_host = 'localhost';
    
    private $_user = "root";
    private $_pass = "root";
    private $_base = "rainer_web";
    
//    private $_user = "web412";
//    private $_pass = "rooter";
//    private $_base = "usr_web412_1";

    private $_char = 'utf8';

    public function __construct() {
        parent::__construct('mysql:host=' . $this->_host . ';dbname=' . $this->_base . ';charset=' . $this->_char . ';', $this->_user, $this->_pass);
    }

    /**
     * To get/initiate PDO instance 
     * 
     * @return PDO resource 
     */
    public static function getInstance() {
        if (!self::$_instance) {
            self::$_instance = new self;
        }
        return self::$_instance;
    }   
}

?> 