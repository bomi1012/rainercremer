<?php
//$a = array(
//    "service1" => array(
//        "number" => 1,
//        "title" => "Heizung",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Heizung"
//    ),
//    "service2" => array(
//        "number" => 2,
//        "title" => "Sanitär",
//        "title-sub" => "Sanitär-sub",
//        "short-content" => "hier ist mein content Sanitär"
//    ),
//    "service3" => array(
//        "number" => 3,
//        "title" => "Solar",
//        "title-sub" => "Solar-sub",
//        "short-content" => "hier ist mein content Solar"
//    )
//);
//
//$toDatabse = base64_encode(serialize($a)); 

?>
<section class="background-color-dark dark" >
    <div class="content-wrap">
        <div id="<?php $html->out($content_service_id); //s. navbar.inc   ?>"   class="page-section container clearfix"> 
            <div class="col_two_third">
                <?php
                $html->content("Unsere <span>Leistungen</span>")->create_h("h4")
                        ->create_div("heading-block fancy-title nobottomborder title-bottom-border")->out();
                ?>
            </div>
            <div class="clear"></div>
        </div>
        <div class="container clearfix">            
            <?php
            if ($context->getParamPage() == AdministrationManager::KEY_ROLE_ADMIN) {
                $services->createPartWithServices(TRUE);
            } else {
                $services->createPartWithServices();
            }
            ?>

            <div class="clear"></div>

        </div>
    </div>
    <div class="parallax nobottommargin background-image-index-leistungen" data-stellar-background-ratio="0.4"></div>
</section><!-- #content end -->