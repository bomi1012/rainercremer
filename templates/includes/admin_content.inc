<!-- ==================Section About================== -->
<?php
//ABOUT_SECTION
$about_left_text = $db->findContent("section-about", "content_about_left");
$about_bottom_text = $db->findContent("section-about", "content_about_bottom");

//TEAM SECTION
if (isset($_POST["admin-submit"])) {
    $about_left_text["content"] = $db->mergeContent($about_left_text["id"], $_POST["content_about_left"], $about_left_text["content"]);
    $about_bottom_text["content"] = $db->mergeContent($about_bottom_text["id"], $_POST["content_about_bottom"], $about_bottom_text["content"]);

  //  $services->merge($_POST["adminSectionServices"], 0);
    
    $team->merge($_POST["adminSectionTeamMembers"], 0);
   // $team->merge($_POST["adminSectionMember"], 1);
}
?>



<form id="admin-form" name="admin-form" class="nobottommargin" action="" method="post">
    <div class="col_full nobottommargin">
        <button class="button button-3d button-green" id="admin-submit" 
                name="admin-submit" value="Save">Speichern</button>
    </div>
    <?php include INC_PATH . 'admin_about.inc'; ?>
    <?php include INC_PATH . 'index_team.inc'; ?>
    <?php //include INC_PATH . 'index_service.inc'; ?>
</form>



