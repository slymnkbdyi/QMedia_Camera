import QtQuick 2.6
import QtQuick.Window 2.2
import QtMultimedia 5.5

//import QtCharts 2.2
import QtQuick.Controls 1.4
import QtLocation 5.3
import QtPositioning 5.8
import QtQuick.Layouts 1.3
import Qt.labs.calendar 1.0

Window
{
    visible: true
    width: 1250
    height: 800
    title: qsTr("Dtsis Player v1.0")

    Rectangle
    {
        id:main_rect

        width: parent.width
        height: parent.height
        Column
        {
            // header stage
            spacing: 5
            Rectangle
            {
                id:header
                width: main_rect.width
                height: main_rect.height*0.75
                radius: 15
                Row
                {
                    spacing: 10
                    Rectangle
                    {
                        id:video_stage
                        width: header.width*0.5
                        height: header.height*0.99

                        Column
                        {
                            spacing: 5
                            // üst videolar
                            Rectangle
                            {
                                id:ust_video
                                height: video_stage.height*0.45
                                width: video_stage.width

                                Row
                                {
                                    spacing: 5
                                    Rectangle
                                    {
                                        id:first_video
                                        height: ust_video.height
                                        width: ust_video.width*0.5
                                        color:"#6495ED"
                                        radius: 15

                                        VideoOutput
                                        {

                                            id:videout
                                            height: first_video.height*0.9

                                            width: first_video.width
                                            source: camera
                                            anchors.centerIn: parent
                                        }

                                        Camera
                                        {

                                            id:camera
                                        }
                                    }
                                    Rectangle
                                    {
                                        id:second_video
                                        height: ust_video.height
                                        width: ust_video.width*0.5
                                        color:"#6495ED"
                                        radius: 15
                                        ShaderEffectSource
                                        {
                                            id: slides1
                                            height: second_video.height*0.9
                                            width: second_video.width
                                            sourceItem: videout
                                            visible:true
                                            anchors.centerIn: parent
                                        }
                                    }
                                }

                            }
                            // alt videolar
                            Rectangle
                            {
                                id:alt_video
                                height: video_stage.height*0.45
                                width: video_stage.width

                                Row

                                {
                                    spacing: 5
                                    Rectangle
                                    {
                                        id:third_video
                                        height: alt_video.height
                                        width: alt_video.width*0.5
                                        color:"#6495ED"
                                        radius: 15
                                        Video
                                        {
                                            id:vid
                                            height: third_video.height*0.9
                                            width: third_video.width*0.9
                                            source: "qrc:///vid.mp4"
                                            anchors.centerIn: parent
                                        }
                                        Component.onCompleted: vid.play();
                                    }
                                    Rectangle
                                    {
                                        id:fourth_video
                                        height: alt_video.height
                                        width: alt_video.width*0.5
                                        color:"#6495ED"
                                        radius: 15
                                        Video
                                        {
                                            id:vid1
                                            height: fourth_video.height*0.9
                                            width: fourth_video.width*0.9
                                            source: "qrc:///vid1.mp4"
                                            anchors.centerIn: parent
                                        }
                                        Component.onCompleted: vid1.play();
                                    }
                                }
                            }
                            // Play Buttons
                            Rectangle
                            {
                                id:play_btn
                                height: video_stage.height*0.09
                                width: video_stage.width
                                radius: 2
                                Row
                                {
                                    spacing: 1
                                    Rectangle
                                    {

                                        height: play_btn.height
                                        width: play_btn.width*0.15
                                        color:"#6495ED"
                                        radius: 2
                                        Button
                                        {

                                            anchors.centerIn: parent

                                            width: parent.width/2
                                            text:"play"
                                        }

                                    }
                                    Rectangle
                                    {

                                        height: play_btn.height
                                        width: play_btn.width*0.15
                                        color:"#6495ED"
                                        radius: 2
                                        Button
                                        {
                                            anchors.centerIn: parent
                                            width: parent.width/2
                                            text:"stop"
                                        }
                                    }
                                    Rectangle
                                    {

                                        height: play_btn.height
                                        width: play_btn.width*0.15
                                        color:"#6495ED"
                                        radius: 2
                                        Button
                                        {
                                            anchors.centerIn: parent
                                            width: parent.width/2
                                            text:"fast"
                                        }
                                    }
                                    Rectangle
                                    {

                                        height: play_btn.height
                                        width: play_btn.width*0.15

                                        color:"#6495ED"
                                        radius: 2
                                        Button
                                        {
                                            anchors.centerIn: parent
                                            width: parent.width/2
                                            text:"slow"
                                        }
                                    }
                                    Rectangle
                                    {

                                        height: play_btn.height
                                        width: play_btn.width*0.15
                                        color:"#6495ED"
                                        radius: 2
                                        Button
                                        {
                                            anchors.centerIn: parent
                                            width: parent.width/2
                                            text:"prev"
                                        }
                                    }
                                    Rectangle
                                    {

                                        height: play_btn.height
                                        width: play_btn.width*0.15
                                        color:"#6495ED"
                                        radius: 2
                                        Button
                                        {
                                            anchors.centerIn: parent
                                            width: parent.width/2
                                            text:"next"
                                        }
                                    }
                                    Rectangle
                                    {

                                        height: play_btn.height
                                        width: play_btn.width*0.1
                                        color:"#6495ED"
                                        radius: 2
                                        Button
                                        {
                                            anchors.centerIn: parent
                                            width: parent.width/2
                                            text:"-"
                                        }
                                    }


                                }
                            }

                        }
                    }
                    Rectangle
                    {
                        id:gallery_stage
                        width: header.width*0.1
                        height: header.height
                        color:"#6495ED"
                        radius: 15

                        GridLayout
                        {
                            id:girdlayout
                            rowSpacing: 1
                            rows:1
                            columns:1
                            anchors.fill: parent
                            Label {
                                id: label1
                                text: qsTr("DEVICE SETTINGS")
                                anchors.horizontalCenter: parent.horizontalCenter
                                font.bold: true

                            }
                            Label {
                                id: label2
                                font.bold: true
                                color:"grey"
                                text: qsTr("Device Id ")

                            }

                            TextField {
                                id: device_id
                                Layout.fillWidth: true
                            }
                            Label
                            {
                                id: label3
                                font.bold: true
                                color:"grey"
                                text: qsTr("Device ip")
                            }

                            TextField {
                                id: device_ip
                                Layout.fillWidth: true
                            }
                            Label
                            {
                                id: label4
                                font.bold: true
                                color:"grey"
                                text: qsTr("Device port")
                            }

                            TextField {
                                id: device_port
                                Layout.fillWidth: true
                            }
                            Button {
                                id: follow_btn
                                Layout.fillWidth: true
                                text:"Follow"

                                onClicked:  follow.take_device_id(""+device_id.text)
                            }

                        }

                    }
                    Rectangle
                    {
                        id:gps_stage
                        width: header.width*0.375
                        height: header.height
                        color:"#6495ED"
                        radius: 15
                        Plugin
                        {
                            id: mapPlugin
                            name: "osm"
                        }

                        Map
                        {
                            id:mAp
                            anchors.fill: parent
                            plugin: mapPlugin

                            zoomLevel:20
                            Route
                            {
                                id:routeData
                            }
                            MapItemView
                            {
                                model:routeModel
                                delegate: Component
                                {
                                    MapRoute
                                    {
                                        route: routeData
                                        line.color: "blue"
                                        line.width: 4
                                    }
                                }
                            }
                            MapQuickItem
                            {
                                id:marker
                                //coordinate: QtPositioning.coordinate(40.984134,28.725093)

                                sourceItem: Image {
                                    id: image
                                    source: "marker.png"
                                }
                                anchorPoint.x: image.width/4
                                anchorPoint.y: image.height

                            }
                            RouteModel
                            {
                                id:routeModel
                                plugin: mapPlugin
                                query: RouteQuery
                                {
                                    id:routeQuery
                                }
                                Component.onCompleted:
                                {
//                                                                       routeQuery.routeOptimizations=routeQuery.ShortestRoute
//                                                                        routeQuery.travelModes=RouteQuery.CarTravel
//                                                                      routeModel.update();
//                                                                      update();

                                }
                            }

                        }
                    }
                }
            }

            // slider stage//

            Rectangle
            {
                id:footer
                width: main_rect.width*0.99
                height: main_rect.height*0.24
                radius: 15
                color:"#6495ED"
//                ChartView
//                {
//                    title: "Line"
//                    anchors.fill: parent
//                    antialiasing: true

//                    LineSeries {
//                        name: "LineSeries"
//                        XYPoint { x: 0; y: 0 }
//                        XYPoint { x: 1.1; y: 2.1 }
//                        XYPoint { x: 1.9; y: 3.3 }
//                        XYPoint { x: 2.1; y: 2.1 }
//                        XYPoint { x: 2.9; y: 4.9 }
//                        XYPoint { x: 3.4; y: 3.0 }
//                        XYPoint { x: 4.1; y: 3.3 }
//                    }
//                }
            }
        }

    }
    Connections
    {
        target: follow
        onSend_gps:
        {
            var startCoordinate = QtPositioning.coordinate(parseFloat(lati), parseFloat(longi));
            routeQuery.addWaypoint(startCoordinate);
            marker.coordinate=startCoordinate
             mAp.center=startCoordinate
            mAp.fitViewportToMapItems();

        if(mAp.zoomLevel>18)
        {
          mAp.zoomLevel=18
        }


            console.log(mAp.zoomLevel);


        //     mAp.zoomLevel--;

//                    routeModel.update();
            console.log(lati,longi);
        }
    }
}
