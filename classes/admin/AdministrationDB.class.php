<?php

class AdministrationDB extends DB {
    
    public function __construct() {   }

    public function getUser($username, $password) {
        $sth = DB::getInstance()->prepare("SELECT * FROM user WHERE username = ? and password = ?");
        $sth->execute(array($username, $password));
        return $sth->fetch(PDO::FETCH_ASSOC);
    }
}

?>
