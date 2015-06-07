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
            if ($admin->isAdmin() == FALSE) {
                $services_hss = $services->getServicesHSS();
            }
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
                                <div>
                                    <h3><span class="subtitle"><?php Util::to_print($value['title-sub']); ?></span></h3>
                                    <p><?php Util::to_print($value['short-content']); ?></p>
                                </div>
                            </div>
                        </div>
                    </div>
                    
                    <?php
                    }
                    ?>
                    
                     

<!--                    <div class="tab-pane fade" id="<?php Util::to_print($sanitär); ?>">
                        <p>1Food truck fixie locavore, accusamus mcsweeney's marfa nulla single-origin coffee squid. Exercitation +1 labore velit, blog sartorial PBR leggings next level wes anderson artisan four loko farm-to-table craft beer twee. Qui photo booth letterpress, commodo enim craft beer mlkshk aliquip jean shorts ullamco ad vinyl cillum PBR. Homo nostrud organic, assumenda labore aesthetic magna delectus mollit. Keytar helvetica VHS salvia yr, vero magna velit sapiente labore stumptown. Vegan fanny pack odio cillum wes anderson 8-bit, sustainable jean shorts beard ut DIY ethical culpa terry richardson biodiesel. Art party scenester stumptown, tumblr butcher vero sint qui sapiente accusamus tattooed echo park.</p>
                    </div>
                    <div class="tab-pane fade" id="<?php Util::to_print($solar); ?>">
                        <p>2Food truck fixie locavore, accusamus mcsweeney's marfa nulla single-origin coffee squid. Exercitation +1 labore velit, blog sartorial PBR leggings next level wes anderson artisan four loko farm-to-table craft beer twee. Qui photo booth letterpress, commodo enim craft beer mlkshk aliquip jean shorts ullamco ad vinyl cillum PBR. Homo nostrud organic, assumenda labore aesthetic magna delectus mollit. Keytar helvetica VHS salvia yr, vero magna velit sapiente labore stumptown. Vegan fanny pack odio cillum wes anderson 8-bit, sustainable jean shorts beard ut DIY ethical culpa terry richardson biodiesel. Art party scenester stumptown, tumblr butcher vero sint qui sapiente accusamus tattooed echo park.</p>
                    </div>
                    <div class="tab-pane fade" id="dropdown1">
                        <p>Etsy mixtape wayfarers, ethical wes anderson tofu before they sold out mcsweeney's organic lomo retro fanny pack lo-fi farm-to-table readymade. Messenger bag gentrify pitchfork tattooed craft beer, iphone skateboard locavore carles etsy salvia banksy hoodie helvetica. DIY synth PBR banksy irony. Leggings gentrify squid 8-bit cred pitchfork. Williamsburg banh mi whatever gluten-free, carles pitchfork biodiesel fixie etsy retro mlkshk vice blog. Scenester cred you probably haven't heard of them, vinyl craft beer blog stumptown. Pitchfork sustainable tofu synth chambray yr.</p>
                    </div>
                    <div class="tab-pane fade" id="dropdown2">
                        <p>Trust fund seitan letterpress, keytar raw denim keffiyeh etsy art party before they sold out master cleanse gluten-free squid scenester freegan cosby sweater. Fanny pack portland seitan DIY, art party locavore wolf cliche high life echo park Austin. Cred vinyl keffiyeh DIY salvia PBR, banh mi before they sold out farm-to-table VHS viral locavore cosby sweater. Lomo wolf viral, mustache readymade thundercats keffiyeh craft beer marfa ethical. Wolf salvia freegan, sartorial keffiyeh echo park vegan.</p>
                    </div>-->
                </div>
            </div><!-- .postcontent end -->
        </div>
    </div>





    <!--    <div class="content-wrap">
            <div id="<?php $html->out($content_service_id); //s. navbar.inc         ?>"   class="page-section container clearfix"> 
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
    if ($admin->isAdmin()) {
        $services->createPartWithServices(TRUE);
    } else {
        $services->createPartWithServices();
    }
    ?>
    
                <div class="clear"></div>
    
            </div>
        </div>
            <div class="parallax nobottommargin background-image-index-leistungen" data-stellar-background-ratio="0.4" /></div>     -->
</section><!-- #content end -->