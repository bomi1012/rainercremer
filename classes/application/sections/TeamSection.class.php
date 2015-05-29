<?php
error_reporting(E_ALL);
class TeamSection extends AbstractSection {

    const TEAM = "team";
    const NUMBER = "number";
    const TITLE = "title";
    const TITLE_SUB = "title-sub";
    const SHORT_CONTENT = "short-content";
    const SHORT_CONTENT_SUB = "short-content-sub";

    /**
     * @var ARRAY 
     */
    private $_arrayTeamMembers;
    private $_arrayMember;

    public function __construct($application) {
        parent::__construct($application);
    }
    
    public function merge($id, $do) {
        $array = $this->fillArrayUsingPOST($do);
        parent::merge($id, $array);
    }

    public function createPartWithMember($admin = FALSE) {
        $dbResult = $this->_application->getDB()->findContent("section-team", "content_team");
        $this->_arrayMember = Util::unserialize64($dbResult[parent::CONTENT]);
        if ($admin != TRUE) {
            $this->printSectionMember();
        } else {
            $this->printAdminSectionMember($dbResult[parent::ID]);
        }
    }

    public function createPartWithTeamMembers($admin = FALSE) {
        $dbResult = $this->_application->getDB()->findContent("section-team", "content_team_list");
        $this->_arrayTeamMembers = Util::unserialize64($dbResult[parent::CONTENT]);
        if ($admin != TRUE) {
            $this->printSectionTeamMembers();
        } else {
            $this->printAdminSectionTeamMembers($dbResult[parent::ID]);
        }
    }

    private function fillArrayUsingPOST($do) {
        $i = 1;
        $save = array();
        if ($do == 0) {
            while (isset($_POST[self::TEAM . $i . "_" . self::TITLE])) {
                $save[self::TEAM . $i] = array(
                    self::NUMBER => $i,
                    self::TITLE => $_POST[self::TEAM . $i . "_" . self::TITLE], //team1_title , title2_title
                    self::TITLE_SUB => $_POST[self::TEAM . $i . "_" . self::TITLE_SUB], //team1_title-sub, team2_title-sub
                    self::SHORT_CONTENT => $_POST[self::TEAM . $i . "_" . self::SHORT_CONTENT] //team1_short-content, team2_short-content
                );
                $i++;
            }
        }
        if ($do == 1) {
            while (isset($_POST["member_" . self::TEAM . $i . "_" . self::TITLE])) {
                $save[self::TEAM . $i] = array(
                    self::NUMBER => $i,
                    self::TITLE => $_POST["member_" . self::TEAM . $i . "_" . self::TITLE], //member_team1_title , member_title2_title
                    self::TITLE_SUB => $_POST["member_" . self::TEAM . $i . "_" . self::TITLE_SUB], //member_team1_title-sub, member_team2_title-sub
                    self::SHORT_CONTENT => $_POST["member_" . self::TEAM . $i . "_" . self::SHORT_CONTENT], //member_team1_short-content, member_team2_short-content
                    self::SHORT_CONTENT_SUB => $_POST["member_" . self::TEAM . $i . "_" . self::SHORT_CONTENT_SUB] //member_team1_short-content, team2_short-content
                );
                $i++;
            }
        }

        return $save;
    }

    private function printSectionTeamMembers() {
        $string = "<div class='container clearfix'>";
        $string .= "<div id='empty' class='col_one_sixth nobottommargin '>
                        <div class='feature-box media-box'>
                            <div class='fbox-media'> </div>
                        </div>
                    </div>";
        for ($index = 1; $index <= 2; $index++) {
            $string .= "<div id='team" . $index . "' class='col_one_third nobottommargin'>";
            $string .= "<div class='feature-box media-box'>";
            $string .= "<div class='fbox-media'>
                                <img src='custom/images/team/member" . $index . ".jpeg' alt='member" . $index . "'>
                            </div>";
            $string .= "<div class='fbox-desc'>
                            <div>
                                <h3>" . $this->_arrayTeamMembers["team" . $index][self::TITLE] . 
                    "<span class='subtitle'>" . $this->_arrayTeamMembers["team" . $index][self::TITLE_SUB] . 
                    "</span></h3>
                                </div>
                                <p>" . $this->_arrayTeamMembers["team" . $index][self::SHORT_CONTENT] . "</p>
                            </div>";            
            $string .= "</div>";
            $string .= "</div>";
        }        
        $string .= "</div>";
        $string .= "<div class='clear bottommargin'></div>";
        $string .= "<div class='container clearfix'>";
        for ($index = 3; $index <= 5; $index++) { 
            $col_last = "";
            if ($index == 5) {
                $col_last = "col_last";
            }
            $string .= "<div id='team" . $index . "' class='col_one_third nobottommargin " . $col_last . "'>";
            $string .= "<div class='feature-box media-box'>";
            $string .= "<div class='fbox-media'>
                                <img src='custom/images/team/member" . $index . ".jpeg' alt='member" . $index . "'>
                            </div>";
            $string .= "<div class='fbox-desc'>
                            <div>
                                <h3>" . $this->_arrayTeamMembers["team" . $index][self::TITLE] . 
                    "<span class='subtitle'>" . $this->_arrayTeamMembers["team" . $index][self::TITLE_SUB] . 
                    "</span></h3>
                                </div>
                                <p>" . $this->_arrayTeamMembers["team" . $index][self::SHORT_CONTENT] . "</p>
                            </div>";            
            $string .= "</div>";
            $string .= "</div>";
        }
        $string .= "</div>";        
        Util::to_print($string);       
    }
    
    private function printAdminSectionTeamMembers($id) {
        foreach ($this->_arrayTeamMembers as $key => $value) {
            $string = "<div id='$key' class='oc-item'>";
            $string .= "<div class='team team-list clearfix'>";
            $string .= $this->_html->content(
                            $this->_html->img(IMG . "team/member" . $value[self::NUMBER] . ".jpeg", NULL, $value[self::TITLE])
                    )->create_div('team-image')->get();
            $string .= "<div class='team-desc'>";
            $string .= "<div class='team-title'>";
            $string .= "<input type='text'
                            id='" . $key . "_" . $value[self::NUMBER] . "_title' 
                            name='" . $key . "_" . self::TITLE . "' 
                            value='" . $value[self::TITLE] . "' class='required simple-input' />";
            $string .= "<input type='text'
                            id='" . $key . "_" . $value[self::NUMBER] . "_title-sub' 
                            name='" . $key . "_" . self::TITLE_SUB . "' 
                            value='" . $value[self::TITLE_SUB] . "' class='simple-input' />";
            $string .= "</div>";
            $string .= "<div class='team-content'>";
            $string .= "<textarea 
                            class='required simple-input textarea_3fields' 
                            id='" . $key . "_" . $value[self::NUMBER] . "_short-content' 
                            name='" . $key . "_" . self::SHORT_CONTENT . "' placeholder='Your Text'>" . $value[self::SHORT_CONTENT] . "</textarea>";
            $string .= "</div>";
            $string .= "</div>";
            $string .= "</div>";
            $string .= "</div>";
            Util::to_print($string);
        }
        Util::to_print("<input type='hidden' name='adminSectionTeamMembers' value='$id'>");
    }

    private function printSectionMember() {
        foreach ($this->_arrayMember as $key => $value) {
            $string = "<div id='team_member_" . $key . "' class='team'>";
            $string .= "<div class='team-title'>";
            $string .= $this->_html->content($value[self::TITLE])->create_h("h4")->get();
            $string .= $this->_html->content($value[self::TITLE_SUB])->create_span()->get();
            $string .= "</div>";
            $string .= "<div class='team-content'>";
            $string .= $this->_html->content(nl2br($value[self::SHORT_CONTENT]))->create_p("lead")->get();
            $string .= $this->_html->content(nl2br($value[self::SHORT_CONTENT_SUB]))->create_p()->get();
            $string .= "</div>";
            $string .= "</div>";
            Util::to_print($string);
        }
    }

    private function printAdminSectionMember($id) {
        $string = "<input type='hidden' name='adminSectionMember' value='$id'>";
        foreach ($this->_arrayMember as $key => $value) {
            $string .= "<div class='team'>";
            $string .= "<div class='team-title'>";
            $string .= "<input type='text'
                            id='member_" . $key . "_" . $value[self::NUMBER] . "_title' 
                            name='member_" . $key . "_" . self::TITLE . "' 
                            value='" . $value[self::TITLE] . "' class='required simple-input' />";

            $string .= "<input type='text'
                            id='member_" . $key . "_" . $value[self::NUMBER] . "_title-sub' 
                            name='member_" . $key . "_" . self::TITLE_SUB . "' 
                            value='" . $value[self::TITLE_SUB] . "' class='simple-input' />";
            $string .= "</div>";
            $string .= "<div class='team-content'>";
            $string .= "<textarea 
                            class='required simple-input textarea_2fields' 
                            id='member_" . $key . "_" . $value[self::NUMBER] . "_short-content' 
                            name='member_" . $key . "_" . self::SHORT_CONTENT . "' placeholder='Your Text'>" . $value[self::SHORT_CONTENT] . "</textarea>";

            $string .= "<textarea 
                            class='required simple-input textarea_1fields' 
                            id='member_" . $key . "_" . $value[self::NUMBER] . "_short-content' 
                            name='member_" . $key . "_" . self::SHORT_CONTENT_SUB . "' placeholder='Your Text'>" . $value[self::SHORT_CONTENT_SUB] . "</textarea>";
            $string .= "</div>";
            $string .= "</div>";
            Util::to_print($string);
        }
    }
}

?>
