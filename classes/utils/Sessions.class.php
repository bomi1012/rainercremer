<?php

class Sessions {
    
    public static function setCoockie($name, $value, $time) {
        setcookie($name, $value, $time);
    }
    
    public static function resetCoockie($name) {
        setcookie($name, "null", time() - 3600);
    }
}

?>
