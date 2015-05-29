<?php
$haftung_fuer_inhalte = "Die Inhalte unserer Seiten wurden mit größter Sorgfalt erstellt. Für die Richtigkeit, 
    Vollständigkeit und Aktualität der Inhalte können wir jedoch keine Gewähr übernehmen. 
    Als Diensteanbieter sind wir gemäß § 7 Abs.1 TMG für eigene Inhalte auf diesen Seiten nach den allgemeinen Gesetzen verantwortlich. 
    Nach §§ 8 bis 10 TMG sind wir als Diensteanbieter jedoch nicht verpflichtet, 
    übermittelte oder gespeicherte fremde Informationen zu überwachen oder nach Umständen zu forschen, 
    die auf eine rechtswidrige Tätigkeit hinweisen. Verpflichtungen zur Entfernung oder Sperrung der Nutzung von 
    Informationen nach den allgemeinen Gesetzen bleiben hiervon unberührt. 
    Eine diesbezügliche Haftung ist jedoch erst ab dem Zeitpunkt der Kenntnis einer konkreten Rechtsverletzung möglich. 
    Bei Bekanntwerden von entsprechenden Rechtsverletzungen werden wir diese Inhalte umgehend entfernen.";

$haftung_fuer_links = "Unser Angebot enthält Links zu externen Webseiten Dritter, auf deren Inhalte wir keinen Einfluss haben. 
    Deshalb können wir für diese fremden Inhalte auch keine Gewähr übernehmen. 
    Für die Inhalte der verlinkten Seiten ist stets der jeweilige Anbieter oder Betreiber der Seiten verantwortlich. 
    Die verlinkten Seiten wurden zum Zeitpunkt der Verlinkung auf mögliche Rechtsverstöße überprüft. 
    Rechtswidrige Inhalte waren zum Zeitpunkt der Verlinkung nicht erkennbar. 
    Eine permanente inhaltliche Kontrolle der verlinkten Seiten ist jedoch ohne konkrete Anhaltspunkte einer Rechtsverletzung nicht zumutbar. 
    Bei Bekanntwerden von Rechtsverletzungen werden wir derartige Links umgehend entfernen.";

$urheberrecht = "Die durch die Seitenbetreiber erstellten Inhalte und Werke auf diesen Seiten unterliegen dem deutschen Urheberrecht. 
    Die Vervielfältigung, Bearbeitung, Verbreitung und jede Art der Verwertung außerhalb der Grenzen des Urheberrechtes bedürfen 
    der schriftlichen Zustimmung des jeweiligen Autors bzw. Erstellers. Downloads und Kopien dieser Seite sind nur für den privaten, 
    nicht kommerziellen Gebrauch gestattet. Soweit die Inhalte auf dieser Seite nicht vom Betreiber erstellt wurden, werden die 
    Urheberrechte Dritter beachtet. Insbesondere werden Inhalte Dritter als solche gekennzeichnet. 
    Sollten Sie trotzdem auf eine Urheberrechtsverletzung aufmerksam werden, bitten wir um einen entsprechenden Hinweis. 
    Bei Bekanntwerden von Rechtsverletzungen werden wir derartige Inhalte umgehend entfernen.";
$datenschutz = "Die Nutzung unserer Webseite ist in der Regel ohne Angabe personenbezogener Daten möglich. 
    Soweit auf unseren Seiten personenbezogene Daten (beispielsweise Name, Anschrift oder eMail-Adressen) erhoben werden, erfolgt dies, 
    soweit möglich, stets auf freiwilliger Basis. Diese Daten werden ohne Ihre ausdrückliche Zustimmung nicht an Dritte weitergegeben. 
    Wir weisen darauf hin, dass die Datenübertragung im Internet (z.B. bei der Kommunikation per E-Mail) Sicherheitslücken aufweisen kann. 
    Ein lückenloser Schutz der Daten vor dem Zugriff durch Dritte ist nicht möglich.
    Der Nutzung von im Rahmen der Impressumspflicht veröffentlichten Kontaktdaten durch Dritte zur Übersendung von nicht ausdrücklich 
    angeforderter Werbung und Informationsmaterialien wird hiermit ausdrücklich widersprochen. 
    Die Betreiber der Seiten behalten sich ausdrücklich rechtliche Schritte im Falle der unverlangten Zusendung von Werbeinformationen, 
    etwa durch Spam-Mails, vor.";
$impressum = "Impressum erstellt durch impressum-generator.de von Franziska Hasselbach, Rechtsanwältin für Arbeitsrecht, Frankfurt";
?>
<!-- Large modal -->
<button  class="btn btn-link" data-toggle="modal" data-target=".bs-modal-lg">Impressum</button>

<div class="modal fade bs-modal-lg" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
        <div class="modal-body">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                    <h4 class="modal-title" id="myModalLabel">Impressum</h4>
                </div>
                <div class="modal-body">
                    <?php
                    $html->content(IConsts::NAME_RAINER_CREMER . "<br /><br />" . IConsts::ADDR_STR . " " .
                            IConsts::ADDR_HOUSE . "<br />" . IConsts::ADDR_PLZ . " " . IConsts::ADDR_ORT . " " .
                            IConsts::ADDR_LAND . "<br /><br />" . IConsts::TEL_TEXT . ": " . IConsts::TEL . "<br />" .
                            IConsts::EMAIL_TEXT . ": " . IConsts::EMAIL)->create_p("lead")->out();

                    $html->content("Haftung für Inhalte")->create_h("h3")->out();
                    $html->content($haftung_fuer_inhalte)->create_h("p")->out();
                    $html->content("Haftung für Links")->create_h("h3")->out();
                    $html->content($haftung_fuer_links)->create_h("p")->out();
                    $html->content("Urheberrecht")->create_h("h3")->out();
                    $html->content($urheberrecht)->create_h("p")->out();
                    $html->content("Datenschutz")->create_h("h3")->out();
                    $html->content($datenschutz)->create_h("p")->out();
                    $html->content($impressum)->create_h("p")->out();
                    ?>
                </div>
            </div>
        </div>
    </div>
</div>