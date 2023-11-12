void calcflbear_(double lat1, double lng1, double lat2, double lng2, double result[2]) {
    lat_1.lat = lat1 * RAD;
    lng_1.lng = lng1 * RAD;
    lat_2.lat = lat2 * RAD;
    lng_2.lng = lng2 * RAD;

    double cl1 = cos(lat_1.lat);
    double cl2 = cos(lat_2.lat);
    double sl1 = sin(lat_1.lat);
    double sl2 = sin(lat_2.lat);
    double delta = lng_2.lng - lng_1.lng;
    double cdelta = cos(delta);
    double sdelta = sin(delta);

    //Calculate bearing
        double x = (cl1 * sl2) - (sl1 * cl2 * cdelta);
        double y = sdelta * cl2;
        double z;
        if(x < 0) {
            z = -((z + 180.0 / 360.0) - 180.0) * RAD;
        } else
            z = atan(-y / x) * DEG;
        double anglerad = (z - (2 * M_PI * floor(z / (2 * M_PI))));
        double bearing = (anglerad * DEG);

    //Calculate flight_dist
        y = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
        x = sl1 * sl2 + cl1 * cl2 * cdelta;

        anglerad = atan2(y, x);
        double flight_dist = anglerad * R_E;
    
    result[0] = bearing;
    result[1] = flight_dist;
}

double calcfldist(double lat1, double lng1, double lat2, double lng2) {
    lat_1.lat = lat1 * RAD;
    lng_1.lng = lng1 * RAD;
    lat_2.lat = lat2 * RAD;
    lng_2.lng = lng2 * RAD;

    double cl1 = cos(lat_1.lat);
    double cl2 = cos(lat_2.lat);
    double sl1 = sin(lat_1.lat);
    double sl2 = sin(lat_2.lat);
    double delta = lng_2.lng - lng_1.lng;
    double cdelta = cos(delta);
    double sdelta = sin(delta);

    double y = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
    double x = sl1 * sl2 + cl1 * cl2 * cdelta;

    double anglerad = atan2(y, x);
    double flight_dist = anglerad * R_E;
    
    return flight_dist;
}

double calcflbear(double lat1, double lng1, double lat2, double lng2) {
    lat_1.lat = lat1 * RAD;
    lng_1.lng = lng1 * RAD;
    lat_2.lat = lat2 * RAD;
    lng_2.lng = lng2 * RAD;

    double cl1 = cos(lat_1.lat);
    double cl2 = cos(lat_2.lat);
    double sl1 = sin(lat_1.lat);
    double sl2 = sin(lat_2.lat);
    double delta = lng_2.lng - lng_1.lng;
    double cdelta = cos(delta);
    double sdelta = sin(delta);

    double x = (cl1 * sl2) - (sl1 * cl2 * cdelta);
    double y = sdelta * cl2;
    double z;
    if(x < 0) {
        z = -((z + 180.0 / 360.0) - 180.0) * RAD;
    } else
        z = atan(-y / x) * DEG;
    double anglerad = (z - (2 * M_PI * floor(z / (2 * M_PI))));
    double bearing = (anglerad * DEG);

    return bearing;
}