<?php
if ($admin->isAdmin() !== FALSE) {
    Util::refreschToPage(AdministrationManager::KEY_ROLE_ADMIN);
}
if (isset($_POST["login-form-submit"])) {
    $admin->login($_POST["login-form-username"], $_POST["login-form-password"]);
}
?>

<div class="content-wrap nopadding">
    <div class="section nopadding nomargin" style="width: 100%; height: 100%; position: absolute; left: 0; top: 0; background: #444;"></div>
    <div class="section nobg full-screen nopadding nomargin">
        <div class="container vertical-middle divcenter clearfix">
            <div class="row center">
                <?php
                $html->content(
                        $html->img(IMG . "logo.png", "login-log", "logo: Reiner Cremer")
                )->create_a(IConsts::INDEX_PHP)->out();
                ?>
            </div>
            <div class="panel panel-default divcenter noradius noborder" style="max-width: 400px;">
                <div class="panel-body" style="padding: 40px;">
                    <form id="login-form" name="login-form" class="nobottommargin" action="" method="post">
                        <h3>Login to your Account</h3>
                        <div class="col_full">
                            <label for="login-form-username">Username:</label>
                            <input type="text" id="login-form-username" name="login-form-username" value="" class="form-control not-dark" />
                        </div>
                        <div class="col_full">
                            <label for="login-form-password">Password:</label>
                            <input type="password" id="login-form-password" name="login-form-password" value="" class="form-control not-dark" />
                        </div>
                        <div class="col_full nobottommargin">
                            <button class="button button-3d button-black nomargin" id="login-form-submit" name="login-form-submit" value="login">Login</button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>