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
        <div id="<?php Util::to_print($content_team_id); ?>" class="page-section container clearfix"> 
            <div class="col_two_third">                
                <?php
                $html->content("Unser <span>Team</span>")->create_h("h4")
                        ->create_div("heading-block fancy-title nobottomborder title-bottom-border")->out();
                ?>        
            </div>
        </div>
        <div class="clear"></div>
        <?php
        if ($admin->isAdmin()) { $team->createPartWithTeamMembers(TRUE);  } 
        else { $team->createPartWithTeamMembers(); }
        ?>
    </div>
    <?php if (!$admin->isAdmin()) { ?>
        <div class="parallax nobottommargin background-image-index-about" data-stellar-background-ratio="0.4" />
    <?php } ?>
</section>