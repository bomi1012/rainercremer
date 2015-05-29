<?php
class MessageMail extends PHPMailer {
    private $_name; 
    private $_email;
    private $_phone;
    private $_message;
    private $_subject ;
    
    private $_botcheck;
    public function getBotcheck() { return $this->_botcheck; }
    
    private $_toemail;
    private $_toname;
    
    public function __construct() {
        parent::__construct();      
    }

    public function isClickedButton() {
        if (isset($_POST['contactform-submit']) AND $_POST['contactform-submit'] == 'submit') {
            return TRUE;
        }
        return FALSE;
    }

    public function isRequiredFieldsOK() {
        if ($_POST['contactform-name'] != '' AND $_POST['contactform-email'] != '' AND $_POST['contactform-message'] != '') {
            return TRUE;
        }
        return FALSE;
    }
    
    public function prepare() {
        $this->_name = $_POST['contactform-name'];
        $this->_email = $_POST['contactform-email'];
        $this->_phone = $_POST['contactform-phone'];
        $this->_message = $_POST['contactform-message'];
        $this->_subject = isset($this->_subject) ? $this->_subject : 'eine Nachricht von reinercremer.de';
        $this->_botcheck = $_POST['contactform-botcheck'];
        
        $this->_toemail =  IConsts::EMAIL;
        $this->_toname = IConsts::NAME_RAINER_CREMER; 
    }
    
    public function sendMail() {
        
        $this->SetFrom($this->_email, $this->_name);
        $this->AddReplyTo($this->_email, $this->_name);
        $this->AddAddress($this->_toemail, $this->_toname);
        $this->Subject = $this->_subject;
        
        $this->_name = isset($this->_name) ? "Name: $this->_name<br>" : '';
        $this->_email = isset($this->_email) ? IConsts::EMAIL_TEXT . ": $this->_email<br>" : '';
        $this->_phone = isset($this->_phone) ? IConsts::TEL_TEXT . ": $this->_phone<br>" : '';
        $this->_message = isset($this->_message) ? "<br>Nachricht:<br> $this->_message<br><br>" : '';
        
        $referrer = $_SERVER['HTTP_REFERER'] ? '<br><br><hr><br>This Form was submitted from: ' . $_SERVER['HTTP_REFERER'] : '';
        $body = "$this->_name $this->_email $this->_phone $this->_message $referrer";
        $this->MsgHTML($body);
        return $this->Send();
    }
    
    public function successfullMessage($html) {
        $button = '<button type="button" class="close" data-dismiss="alert" aria-hidden="true">x</button>';
        $icon = '<i class="icon-paperplane"></i>';
        $text = 'Ihre Nachricht wurde erfolgreich gesendet';
        
        return $html->content($button . $icon . $text)->create_div("alert alert-success")->get();
    }
}
?>
