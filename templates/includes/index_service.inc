<?php
//$a = array(
//    "service1" => array(
//        "number" => 1,
//        "title" => "Montageservice",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Montageservice"
//    ),
//    "service2" => array(
//        "number" => 2,
//        "title" => "Duschkabine",
//        "title-sub" => "Sanitär-sub",
//        "short-content" => "hier ist mein content Duschkabine"
//    ),
//    "service3" => array(
//        "number" => 3,
//        "title" => "Solar",
//        "title-sub" => "Solar-sub",
//        "short-content" => "hier ist mein content Solar"
//    ),
//    "service4" => array(
//        "number" => 4,
//        "title" => "Solar",
//        "title-sub" => "Solar-sub",
//        "short-content" => "hier ist mein content Solar"
//    ),
//    "service5" => array(
//        "number" => 5,
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
        <div class="container clearfix">
            <div id="<?php Util::to_print($content_service_id); ?>" class="page-section container clearfix"> 
                <div class="col_two_third">                
                    <?php
                    $html->content("Unser <span>Leistungen</span>")->create_h("h4")
                            ->create_div("heading-block fancy-title nobottomborder title-bottom-border")->out();
                    ?>        
                </div>
            </div>                        
            <?php
            $services_hss = $services->getServicesHSS();
            ?>
            <!-- Post Content
            ============================================= -->
            <div class="postcontent-mb nobottommargin clearfix">
                <ul id="myTab" class="nav nav-tabs boot-tabs">
                    <?php
                    foreach ($services_hss as $key => $value) {
                        $active = "";
                        if (key($services_hss) == $key) {
                            $active = "class='active'";
                        }
                        ?>
                        <li <?php Util::to_print($active); ?>>
                            <a href="#<?php Util::to_print($key); ?>" data-toggle="tab">
                                <?php Util::to_print($value['title']); ?>
                            </a>
                        </li>
                        <?php
                    }
                    ?>
                </ul>

                <div id="myTabContent" class="tab-content">
                    <?php
                    foreach ($services_hss as $key => $value) {
                        $active = "";
                        if (reset($services_hss) == $value) {
                            $active = "active";
                        }
                        ?>

                        <div class="tab-pane fade in <?php Util::to_print($active); ?>" id="<?php Util::to_print($key); ?>">   
                            <div class="container clearfix feature-box media-box">
                                <div id="service_<?php Util::to_print($value['number']); ?>" class="col_one_third nobottommargin ">
                                    <div class="feature-box media-box">
                                        <div class="fbox-media">
                                            <img src="custom/images/team/member3.jpeg" alt="member3">
                                        </div>
                                    </div>
                                </div>
                                <div id="team4" class="col_three_fifth nobottommargin col_last">
                                    <?php
                                    if ($admin->isAdmin() == FALSE) {
                                        ?>
                                        <div>
                                            <h3><span class="subtitle"><?php Util::to_print($value['title-sub']); ?></span></h3>
                                            <p><?php Util::to_print($value['short-content']); ?></p>
                                        </div>
                                        <?php
                                    } else {
                                        echo "<input type='text'
                            id='" . $key . "_" . $value[ServiceSection::NUMBER] . "_title' 
                            name='" . $key . "_" . ServiceSection::TITLE . "' 
                            value='" . $value[ServiceSection::TITLE] . "' class='required simple-input' />" .
                                        "<input type='text'
                            id='" . $key . "_" . $value[ServiceSection::NUMBER] . "_title-sub' 
                            name='" . $key . "_" . ServiceSection::TITLE_SUB . "' 
                            value='" . $value[ServiceSection::TITLE_SUB] . "' class='simple-input' />" .
                                        "<textarea class='required simple-input textarea_3fields' 
                            id='" . $key . "_" . $value[ServiceSection::NUMBER] . "_short-content' 
                            name='" . $key . "_" . ServiceSection::SHORT_CONTENT . "' placeholder='Your Text'>" .
                                        $value[ServiceSection::SHORT_CONTENT] . "</textarea>" .
                                        "<input type='hidden' name='adminSectionServices' value='" . $services->getId() . "'>";
                                    }
                                    ?>
                                </div>
                            </div>
                        </div>
    <?php
}
?>
                </div>
            </div><!-- .postcontent end -->
        </div>
    </div>
      <div class="section section_about nomargin noborder bgcolor dark" data-stellar-background-ratio="0.3">
        <div id="content_about_bottom" class="heading-block center nobottomborder nobottommargin">
            <?php
            $html->content("klsfjkldsfklsfjklsfjskldf")->create_h("h2")->out();
            ?>
        </div>
    </div>
</section><!-- #content end -->