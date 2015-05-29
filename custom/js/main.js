/**
 * TEAM
 */
jQuery(document).ready(function($) {

    var ocTeam = $("#oc-team-list");

    ocTeam.owlCarousel({
        responsive: {
            0: {items: 1},
            600: {items: 1},
            1000: {items: 2}
        },
        margin: 30,
        nav: false,
        dots: true
    });
});

/**
 * GMAP
 */
jQuery(window).load(function() {
    jQuery('#headquarters-map').gMap({
        address: 'Bahnhofstraße 16, 76889 Steinfeld Deutschland',
        maptype: 'ROADMAP',
        zoom: 17,
        markers: [
            {
                address: "Bahnhofstraße 16, 76889 Steinfeld Deutschland",
                // html: "Bahnhofstraße 16, 76889 Steinfeld Deutschland",
                icon: {
                    image: "http://maps.google.com/mapfiles/ms/micons/grn-pushpin.png",
                    iconsize: [32, 32],
                    iconanchor: [14, 44]
                }
            }
        ],
        doubleclickzoom: false,
        controls: {
            panControl: false,
            zoomControl: false,
            mapTypeControl: false,
            scaleControl: false,
            streetViewControl: false,
            overviewMapControl: false
        },
        styles: [{"featureType": "all", "elementType": "labels.text.fill", "stylers": [{"saturation": 36}, {"color": "#000000"}, {"lightness": 40}]}, {"featureType": "all", "elementType": "labels.text.stroke", "stylers": [{"visibility": "on"}, {"color": "#000000"}, {"lightness": 16}]}, {"featureType": "all", "elementType": "labels.icon", "stylers": [{"visibility": "off"}]}, {"featureType": "administrative", "elementType": "geometry.fill", "stylers": [{"color": "#000000"}, {"lightness": 20}]}, {"featureType": "administrative", "elementType": "geometry.stroke", "stylers": [{"color": "#000000"}, {"lightness": 17}, {"weight": 1.2}]}, {"featureType": "administrative", "elementType": "labels", "stylers": [{"visibility": "off"}]}, {"featureType": "administrative.country", "elementType": "all", "stylers": [{"visibility": "simplified"}]}, {"featureType": "administrative.country", "elementType": "geometry", "stylers": [{"visibility": "simplified"}]}, {"featureType": "administrative.country", "elementType": "labels.text", "stylers": [{"visibility": "simplified"}]}, {"featureType": "administrative.province", "elementType": "all", "stylers": [{"visibility": "off"}]}, {"featureType": "administrative.locality", "elementType": "all", "stylers": [{"visibility": "simplified"}, {"saturation": "-100"}, {"lightness": "30"}]}, {"featureType": "administrative.neighborhood", "elementType": "all", "stylers": [{"visibility": "off"}]}, {"featureType": "administrative.land_parcel", "elementType": "all", "stylers": [{"visibility": "off"}]}, {"featureType": "landscape", "elementType": "all", "stylers": [{"visibility": "simplified"}, {"gamma": "0.00"}, {"lightness": "74"}]}, {"featureType": "landscape", "elementType": "geometry", "stylers": [{"color": "#000000"}, {"lightness": 20}]}, {"featureType": "landscape.man_made", "elementType": "all", "stylers": [{"lightness": "3"}]}, {"featureType": "poi", "elementType": "all", "stylers": [{"visibility": "off"}]}, {"featureType": "poi", "elementType": "geometry", "stylers": [{"color": "#000000"}, {"lightness": 21}]}, {"featureType": "road", "elementType": "geometry", "stylers": [{"visibility": "simplified"}]}, {"featureType": "road.highway", "elementType": "geometry.fill", "stylers": [{"color": "#000000"}, {"lightness": 17}]}, {"featureType": "road.highway", "elementType": "geometry.stroke", "stylers": [{"color": "#000000"}, {"lightness": 29}, {"weight": 0.2}]}, {"featureType": "road.arterial", "elementType": "geometry", "stylers": [{"color": "#000000"}, {"lightness": 18}]}, {"featureType": "road.local", "elementType": "geometry", "stylers": [{"color": "#000000"}, {"lightness": 16}]}, {"featureType": "transit", "elementType": "geometry", "stylers": [{"color": "#000000"}, {"lightness": 19}]}, {"featureType": "water", "elementType": "geometry", "stylers": [{"color": "#000000"}, {"lightness": 17}]}]
    });
});