<?php
//$a = array(
//    "team1" => array(
//        "number" => 1,
//        "title" => "Heizung",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Heizung",
//        "short-content-sub" => "hier ist mein content Heizung"
//    )
//);
//$toDatabse = base64_encode(serialize($a)); 
//$a = array(
//    "team1" => array(
//        "number" => 1,
//        "title" => "Heizung",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Heizung"
//    ),
//    "team2" => array(
//        "number" => 2,
//        "title" => "Heizung",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Heizung"
//    ),
//    "team3" => array(
//        "number" => 3,
//        "title" => "Heizung",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Heizung"
//    ),
//    "team4" => array(
//        "number" => 4,
//        "title" => "Heizung",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Heizung"
//    ),
//    "team5" => array(
//        "number" => 5,
//        "title" => "Heizung",
//        "title-sub" => "Heizung-sub",
//        "short-content" => "hier ist mein content Heizung"
//    )
//);
//$toDatabse = base64_encode(serialize($a)); 
?>
<section id="section-team"  class="background-color-dark dark">
    <div class="content-wrap">
        <div id="content-team" class="page-section container clearfix"> 
            <div class="col_two_third">
                <div class="heading-block fancy-title nobottomborder title-bottom-border">
                    <h4>Unser <span>Team</span></h4>
                </div>           
            </div>
        </div>
        <div class="clear"></div>
        <?php
        if ($context->getParamPage() == AdministrationManager::KEY_ROLE_ADMIN) {
            $team->createPartWithTeamMembers(TRUE);
        } else {
            $team->createPartWithTeamMembers();
        }
        ?>
    </div>
    <div class="parallax nobottommargin background-image-index-about" data-stellar-background-ratio="0.4"></div>
</section>