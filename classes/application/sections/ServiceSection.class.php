<?php

class ServiceSection extends AbstractSection {

    const SERVICE = "service";
    const NUMBER = "number";
    const TITLE = "title";
    const TITLE_SUB = "title-sub";
    const SHORT_CONTENT = "short-content";

    private $_arrayServicesHSS = NULL;

    public function __construct($application) {
        parent::__construct($application);
        $this->init();
    }

    public function getServicesHSS() {
        if ($this->_arrayServicesHSS == NULL) {
            $this->init();
        }
        return $this->_arrayServicesHSS;
    }
    
    

    
    private function init() {
        $dbResult = $this->_application->getDB()->findContent("section-service", "content_service_list");
        $this->_arrayServicesHSS = Util::unserialize64($dbResult[parent::CONTENT]);
    } 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    public function merge($id, $do) {
        $array = $this->fillArrayUsingPOST($do);
        parent::merge($id, $array);
    }

    public function createPartWithServices($admin = FALSE) {
        $dbResult = $this->_application->getDB()->findContent("section-service", "content_service_list");
        $this->_arrayServicesHSS = Util::unserialize64($dbResult[parent::CONTENT]);
        if ($admin != TRUE) {
            $this->printSectionServices();
        } else {
            $this->printAdminSectionServices($dbResult[parent::ID]);
        }
    }

    private function fillArrayUsingPOST($do) {
        $i = 1;
        $save = array();
        if ($do == 0) {
            while (isset($_POST[self::SERVICE . $i . "_" . self::TITLE])) {
                $save[self::SERVICE . $i] = array(
                    self::NUMBER => $i,
                    self::TITLE => $_POST[self::SERVICE . $i . "_" . self::TITLE], //member_team1_title , member_title2_title
                    self::TITLE_SUB => $_POST[self::SERVICE . $i . "_" . self::TITLE_SUB], //member_team1_title-sub, member_team2_title-sub
                    self::SHORT_CONTENT => $_POST[self::SERVICE . $i . "_" . self::SHORT_CONTENT], //member_team1_short-content, member_team2_short-content
                );
                $i++;
            }
        }
        return $save;
    }

    private function printSectionServices() {
        foreach ($this->_arrayServicesHSS as $key => $value) {
            $subTitle = $this->_html->content($value[self::TITLE_SUB])->create_span("subtitle")->get();
            $string_title = $this->_html->content($value[self::TITLE] . " " . $subTitle)->create_h("h3")->get();

            $col_last = "";
            $el = end($this->_arrayServicesHSS);
            if ($el[self::NUMBER] == $value[self::NUMBER]) {
                $col_last = "col_last";
            }
            $string = "<div id='$key' class='col_one_third nobottommargin $col_last'>";
            $string .= "<div class='feature-box media-box'>";
            $string .= $this->_html->content(
                            $this->_html->img(IMG . "service/services" . $value[self::NUMBER] . ".jpeg", NULL, $value[self::TITLE])
                    )->create_div('fbox-media')->get();
            $string .= "<div class='fbox-desc'>";
            $string .= $this->_html->content($string_title)->create_div()->get();
            $string .= $this->_html->content(nl2br($value[self::SHORT_CONTENT]))->create_p()->get();
            $string .= "</div>";
            $string .= "</div>";
            $string .= "</div>";
            Util::to_print($string);
        }
    }

    private function printAdminSectionServices($id) {
        foreach ($this->_arrayServicesHSS as $key => $value) {
            $col_last = "";
            $el = end($this->_arrayServicesHSS);
            if ($el[self::NUMBER] == $value[self::NUMBER]) {
                $col_last = "col_last";
            }
            $string = "<div id='$key' class='col_one_third nobottommargin $col_last'>";
            $string .= "<div class='feature-box media-box'>";

            $string .= "<input type='text'
                            id='" . $key . "_" . $value[self::NUMBER] . "_title' 
                            name='" . $key . "_" . self::TITLE . "' 
                            value='" . $value[self::TITLE] . "' class='required simple-input' />";
            $string .= "<input type='text'
                            id='" . $key . "_" . $value[self::NUMBER] . "_title-sub' 
                            name='" . $key . "_" . self::TITLE_SUB . "' 
                            value='" . $value[self::TITLE_SUB] . "' class='simple-input' />";
            $string .= "<div class='fbox-desc'>";
            $string .= "<textarea 
                            class='required simple-input textarea_3fields' 
                            id='" . $key . "_" . $value[self::NUMBER] . "_short-content' 
                            name='" . $key . "_" . self::SHORT_CONTENT . "' placeholder='Your Text'>" . $value[self::SHORT_CONTENT] . "</textarea>";
            $string .= "</div>";
            $string .= "</div>";
            $string .= "</div>";
            Util::to_print($string);
        }
        Util::to_print("<input type='hidden' name='adminSectionServices' value='$id'>");
    }

}

?>
