// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "augustus",
    products: [
        .library(
            name: "CAugustus",
            targets: ["CAugustus"]),
    ],
    dependencies: [
        
    ],
    targets: [
        .target(
            name: "CAugustus",
            dependencies: ["CSDL2"],
            path: "./src",
            exclude: [
                "./platform/android",
                "./platform/emscripten",
                "./platform/haiku",
                "./platform/switch",
                "./platform/vita",
                "./platform/augustus.c"
            ],
            sources: [
                "../ext/tinyfiledialogs",
                "./assets",
                "./building",
                "./city",
                "./core",
                "./editor",
                "./empire",
                "./figure",
                "./figuretype",
                "./game",
                "./graphics",
                "./input",
                "./map",
                "./platform",
                "./scenario",
                "./sound",
                "./translation",
                "./widget",
                "./window"
            ],
            resources: [.copy("../assets")],
            publicHeadersPath: "modules",
            cSettings: [
                .headerSearchPath("."),
                .headerSearchPath("../ext"),
                .headerSearchPath("../ext/png")
            ],
            linkerSettings: [
                
            ]),
        
        .systemLibrary(
            name: "CSDL2",
            path: "./modules/CSDL2",
            pkgConfig: "sdl2",
            providers: [
                .brew(["sdl2"]),
                .apt(["libsdl2-dev"])
            ]
        ),
    ],
    cLanguageStandard: .gnu99
)
