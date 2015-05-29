<?php

class ApplicationContextDB extends DB {

    public function __construct() { }

    /**
     * 
     * @param String or NULL $param1
     * @param String or NULL $param2
     * @return ARRAY
     */
    public function getPageUsingParams($param1, $param2) {
        $param1 == null ? $s1 = "param1 is ?" : $s1 = "param1 = ?";
        $param2 == null ? $s2 = "param2 is ?" : $s2 = "param2 = ?";
        $sth = DB::getInstance()->prepare("SELECT * FROM pages WHERE " . $s1 . " AND " . $s2);
        $sth->execute(array($param1, $param2));
        return $sth->fetch(PDO::FETCH_ASSOC);
    }

    public function findContent($contentName, $contentId) {
        $sth = DB::getInstance()->prepare("SELECT id, content FROM sections WHERE content_name = ? AND content_id = ?");
        $sth->execute(array($contentName, $contentId));
        return $sth->fetch(PDO::FETCH_ASSOC);
    }
    
    public function mergeContent($id, $new, $old = NULL) {
        if ($old != NULL) {
            $result = Util::compareStrings($new, $old);
            if ($result != 0) {
                $this->update($id, $new, "sections");
            }
        } else {
            $this->update($id, $new, "sections");
        }
        return $new;
    }

    public function update($id, $content, $table) {
        $sth = DB::getInstance()->prepare("UPDATE " . $table . " SET content = ? WHERE id = ?");
        $sth->execute(array($content, $id));
    }



}

?>
