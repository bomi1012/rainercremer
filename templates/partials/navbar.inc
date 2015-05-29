<?php
/* @var $navi NavigationService */
$elements = $navi->getNavigationElements();

$header = $elements[0]->getData_href(); // "header";
$content_about_id = $elements[1]->getData_href(); // "content-about";
$content_team_id = $elements[2]->getData_href();  // "content-team";
//$content_service_id = $elements[3]->getData_href();  // "content-service";
$content_contact_id = $elements[4]->getData_href();  // "content-contact";
?>
<!-- Header ============================================= -->
<header id="header" class="sticky-style-2 dark page-section">
    <div class="container clearfix">
        <!-- Logo ============================================= -->
        <div id="logo" class="visible-lg">
            <?php
            $html->content(
                    $html->img(IMG . "logo.png", "logo-top", IConsts::LOGO_TEXT)
            )->create_a(IConsts::INDEX_PHP, "standard-logo")->out();
            ?>
        </div><!-- #logo end -->
        <ul class="header-extras">
            <li>
                <i class="i-plain icon-email3 nomargin"></i>
                <div class="he-text">
                    <?php
                    $html->content(
                            IConsts::EXTRA_TEXT_1 . $html->content(IConsts::EMAIL)->create_span()->get()
                    )->out();
                    ?>
                </div>
            </li>
            <li>
                <i class="i-plain icon-call nomargin"></i>
                <div class="he-text">
                    <?php
                    $html->content(
                            IConsts::EXTRA_TEXT_2 . $html->content("Tel.: " . IConsts::TEL . "<br />Mob.: " . IConsts::MOB)
                                    ->create_span()->get()
                    )->out();
                    ?>
                </div>
            </li>
        </ul>
    </div>

    <div id="header-wrap">
        <!-- Primary Navigation  ============================================= -->
        <nav id="primary-menu" class="style-2">
            <div class="container clearfix">
                <div id="primary-menu-trigger">
                    <i class="icon-reorder"></i>
                </div>
                
                <?php $html->out($navi->buildNavigationMenu()); ?>
                

            </div>
        </nav><!-- #primary-menu end -->
    </div>
</header><!-- #header end -->
