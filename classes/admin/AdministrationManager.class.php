<?php

class AdministrationManager {

    const ROLE = "role";
    const KEY_ROLE_ADMIN = "admin";
    const PAGE_LOGIN = "login";
    static private $instance = null;
    private $_adminDB;
    
    public function __construct() {
        $this->_adminDB = new AdministrationDB();
    }

    static public function getInstance() {
        if (null === self::$instance) {
            self::$instance = new self;
        }
        return self::$instance;
    }

    public function isAdmin() {        
        if (isset($_COOKIE[self::ROLE]) && $_COOKIE[self::ROLE] == self::KEY_ROLE_ADMIN) {
            return TRUE;
        } 
        return FALSE;
    }
    
    public function login($username, $password) {
        $passwort_md5 = md5(md5($password));
        $user = $this->_adminDB->getUser($username, $passwort_md5);

        if ($user !== FALSE) {
            Sessions::setCoockie(self::ROLE, $user[self::ROLE], time() + 60 * 60 * 24 * 30);
            Util::refreschToPage(AdministrationManager::KEY_ROLE_ADMIN);
        }
        return FALSE;
    }
}

?>
