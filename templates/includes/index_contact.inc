<section class="background-color-dark dark" >
    <div id="contact-id" class="page-section content-wrap nobottompadding nobottommargin">
        <div id="<?php echo $content_contact_id; ?>" class="page-section container clearfix"> 
            <div class="col_two_third">
                <?php
                $html->content("Kontakte <span>Location</span>")->create_h("h4")
                        ->create_div("heading-block fancy-title nobottomborder title-bottom-border")->out();
                ?>
            </div>
            <div class="clear"></div>
        </div>

        <div class="container clearfix background-color-dark dark" >
            <?php
            $mail = new MessageMail();
            if ($mail->isClickedButton() && $mail->isRequiredFieldsOK()) {
                $mail->prepare();
                $isSended = FALSE;
                if ($mail->getBotcheck() == '') {
                    $isSended = $mail->sendMail();
                }
                if ($isSended) {
                    Util::to_print($mail->successfullMessage($html));
                }
            }
            ?>
            <form class="nobottommargin" id="contactform" name="contactform" action="#contact-id" method="post">
                <div class="col_two_fifth">
                    <div class="col_full">
                        <input type="text" 
                               id="contactform-name" 
                               name="contactform-name" 
                               value="" class="input_style sm-form-control border-form-control required" 
                               placeholder="<?php Util::to_print("Name"); ?>" required/>
                    </div>
                    <div class="col_full">
                        <input type="email" id="contactform-email" name="contactform-email" 
                               value="" 
                               class="required email sm-form-control border-form-control" 
                               placeholder="<?php Util::to_print("E-Mail-Adresse"); ?>" required />
                    </div>
                    <div class="col_full">
                        <input type="text" id="contactform-phone" name="contactform-phone" 
                               value="" class="sm-form-control border-form-control" 
                               placeholder="<?php Util::to_print("Telefon"); ?>" />
                    </div>
                </div>
                <div class="col_three_fifth col_last">
                    <textarea class="required sm-form-control border-form-control textarea_3fields" id="contactform-message" 
                              name="contactform-message" placeholder="<?php Util::to_print("Ihre Nachricht"); ?>" required></textarea>
                </div>
                <div class="col_full center">
                    <button class="button button-border button-circle t500 noleftmargin topmargin-sm" 
                            type="submit" 
                            id="id-contactform-submit" 
                            name="contactform-submit" 
                            value="submit"><?php Util::to_print("Nachricht senden"); ?></button>
                    <br>
                </div>
                <div class="clear"></div>
                <div class="col_full hidden">
                    <input type="text" id="contactform-botcheck" name="contactform-botcheck" value="" class="sm-form-control" />
                </div>
            </form>
        </div>


        <div class="row noleftmargin norightmargin common-height">
            <div id="headquarters-map" class="col-md-8 col-sm-6 gmap hidden-xs"></div>
            <div class="col-md-4 col-sm-6" style="background-color: #282828;">
                <div class="col-padding max-height">
                    
                    <div style="font-size: 16px; line-height: 1.7;">
                        <?php $html->content(IConsts::ADDR_TEXT)->create_h("h3")->out(); ?>
                        
                        <address style="line-height: 1.7;">
                            <?php Util::to_print(IConsts::ADDR_STR . " " . IConsts::ADDR_HOUSE); ?> <br />
                            <?php Util::to_print(IConsts::ADDR_PLZ . " " . IConsts::ADDR_ORT); ?> <br />
                            <?php Util::to_print(IConsts::ADDR_LAND); ?>
                        </address>
                        <div class="clear topmargin-sm"></div>
                        <?php $html->content(IConsts::KONTAKDATEN)->create_h("h3", "font-body t400 ls1")->out();?>
                        <strong><?php Util::to_print(IConsts::TEL_TEXT); ?>: </strong> <?php Util::to_print(IConsts::TEL); ?><br />
                        <strong><?php Util::to_print(IConsts::MOB_TEXT); ?>: </strong> <?php Util::to_print(IConsts::MOB); ?><br />
                        <strong><?php Util::to_print(IConsts::EMAIL_TEXT); ?>: </strong><?php Util::to_print(IConsts::EMAIL); ?>
                    </div>
                </div>
            </div>
        </div>
        <script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=true"></script>
        <script type="text/javascript" src="base/js/jquery.gmap.js"></script>
    </div>
</section>
