<?php

class HTMLElementsBuilder {

    const ID = "id";
    const CL = "class";
    const ALT = "alt";

    private $_content;

    public function get() {
        return $this->_content;
    }

    public function __construct() {
        
    }

    public function content($content) {
        $this->_content = $content;
        return $this;
    }

    public function create_p($class = NULL, $id = NULL) {
        $open = "<p " . $this->attr($id, self::ID) . $this->attr($class, self::CL) . ">";
        return $this->create($open, "</p>");
    }

    public function create_h($h, $class = NULL, $id = NULL) {
        $open = "<" . $h . $this->attr($id, self::ID) . $this->attr($class, self::CL) . ">";
        return $this->create($open, "</$h>");
    }

    public function create_span($class = NULL, $id = NULL) {
        $open = "<span" . $this->attr($id, self::ID) . $this->attr($class, self::CL) . ">";
        return $this->create($open, "</span>");
    }

    public function create_a($href, $class = NULL, $id = NULL) {
        $open = "<a href='" . $href . "'" . $this->attr($id, self::ID) . $this->attr($class, self::CL) . ">";
        return $this->create($open, "</a>");
    }
    
    public function create_div($class = NULL, $id = NULL) {
        $open = "<div" . $this->attr($id, self::ID) . $this->attr($class, self::CL) . ">";
        return $this->create($open, "</div>");
    }

    public function img($src, $class = NULL, $alt = NULL, $id = NULL) {
        return "<img src='" . $src . "'" . $this->attr($id, self::ID) . $this->attr($class, self::CL) . $this->attr($alt, self::ALT) . ">";
    }
    
    public function out($content = NULL) {
        if ($content == NULL) {
            echo Util::to_print($this->_content);
        } else {
            echo Util::to_print($content);
        }
    }

    private function attr($attr, $key) {
        $attr == null ? $result = "" : $result = " " . $key . "='" . $attr . "' ";
        return $result;
    }

    private function create($tag_open, $tag_close) {
        $this->_content = $tag_open . $this->_content . $tag_close;
        return $this;
    }
}

?>
