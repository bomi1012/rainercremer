<?php

class Util {

    public static final function to_print($text, $umlaute = TRUE) {
        if ($umlaute == TRUE) {
            echo self::umlaute($text);
        } else {
            echo $text;
        }
    }

    private static final function umlaute($text) {
        $search = array('ä', 'ö', 'ü', 'Ä', 'Ö', 'Ü', 'ß');
        $replace = array('&auml;', '&ouml;', '&uuml;', '&Auml;', '&Ouml;', '&Uuml;', '&szlig;');
        return str_replace($search, $replace, $text);
    }

    public static function refreschToPage($page) {
        header('Location: ' . PATH . $page);
    }
    
    public static function compareStrings($s1, $s2) {
        return strcmp($s1, $s2);
    }    
    
    public static function serialize64($data) {
        return base64_encode(serialize($data));
    }
    
    public static function unserialize64($data) {
        return unserialize(base64_decode($data));
    }
}

?>
