<?php

class ApplicationContextManager {

    const INC_SUF = ".inc";
    const PARAM_PAGE = "page";
    const PARAM_SUBPAGE = "subpage";
    const TITLE = "title";

    /**
     * @var ApplicationContextModel
     */
    private $_context;
    public function getContext() {
        return $this->_context;
    }

    /**
     * @var  DB
     */
    private $_db;
    public function getDB() {
        return $this->_db;
    }

    private $_isLoginPage;
    public function isLoginPage() {
        return $this->_isLoginPage;
    }

    public function __construct($param = null) {
        $this->init();
        $this->setParams();
        $this->setProperties($this->_db->getPageUsingParams($this->_context->getParamPage(), $this->_context->getParamSubPage()));
    }

    private function init() {
        $this->_context = new ApplicationContextModel();
        $this->_db = new ApplicationContextDB();
        $this->_isLoginPage = FALSE;
    }

    private function setParams() {
        if (isset($_GET[self::PARAM_PAGE])) {
            $this->_context->setParamPage($_GET[self::PARAM_PAGE]);
        }
        if (isset($_GET[self::PARAM_SUBPAGE])) {
            $this->_context->setParamSubPage($_GET[self::PARAM_SUBPAGE]);
            if ($this->_context->getParamPage() == AdministrationManager::KEY_ROLE_ADMIN 
                    && $this->_context->getParamSubPage() == AdministrationManager::PAGE_LOGIN) {
                $this->_isLoginPage = TRUE;
            }
        }
    }

    private function setProperties($array) {
        if ($array != NULL) {
            $this->_context->setPathInlude($array[self::PARAM_PAGE] . self::INC_SUF);
            $this->_context->setTitle($array[self::TITLE]);
        } else {
            //FIXME
        }
    }

}

?>
