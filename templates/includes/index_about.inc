<?php
$text = $db->findContent("section-about", "content_about_left");
$slogan = $db->findContent("section-about", "content_about_bottom");
$content_about_right = $html->content(IConsts::MONTAGESERVICE)->create_span()->get() . " " . IConsts::NAME_RAINER_CREMER;
?>
<section id="section-about" class="background-color-dark dark" >
    <div class="content-wrap">
        <div id="<?php $html->out($content_about_id); ?>" class="page-section container clearfix"> 
            <div id="content_about_left" class="col_two_third">
                <div class="heading-block fancy-title nobottomborder title-bottom-border">
                    <?php $html->content($content_about_right)->create_h("h4")->out(); ?>
                </div>
                <?php $html->content(nl2br($text["content"]))->create_p("lead")->out(); ?>
            </div>
            <div class="col_one_third col_last">
                <div class="accordion accordion-border clearfix accordion-margin-top">
                    <div class="acctitle acctitlec">
                        <i class="acc-closed icon-ok-circle"></i>
                        <i class="acc-open icon-remove-circle"></i>
                        <?php $html->out(IConsts::KONTAKDATEN); ?>
                    </div>
                    <div class="acc_content clearfix" style="display: block;">
                        <?php
                        $list = IConsts::TEL_TEXT . ": " . IConsts::TEL . " 
                                " . IConsts::MOB_TEXT . ": " . IConsts::MOB . "
                                " . IConsts::EMAIL_TEXT . ": " . IConsts::EMAIL . "
                                " . IConsts::ADDR_TEXT . ": " . IConsts::ADDR_STR . " " . IConsts::ADDR_HOUSE . ", " . IConsts::ADDR_PLZ 
                                  . " " . IConsts::ADDR_ORT;
                        $html->out(nl2br($list));
                        ?>
                    </div>

         <!--             <div class="acctitle">
                        <i class="acc-closed icon-ok-circle"></i>
                        <i class="acc-open icon-remove-circle"></i>
                        <?php $html->out(IConsts::OEFFNUNGSZEITEN); ?>                        
                    </div>
                  <div class="acc_content clearfix" style="display: none;">
                        <?php Util::to_print("Monntag-Freitag: 08:00 - 18:00 <br /> Sammstag, Sonntag: geschloßen"); ?>
                    </div>-->
                </div>
            </div>
        </div>
    </div>

    <div class="section section_about nomargin noborder bgcolor dark" data-stellar-background-ratio="0.3">
        <div id="content_about_bottom" class="heading-block center nobottomborder nobottommargin">
            <?php
            $html->content($slogan["content"])->create_h("h2")->out();
            ?>
        </div>
    </div>
</section><!-- #section about end -->