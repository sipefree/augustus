// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "augustus",
    platforms: [
        .macOS(.v11)
    ],
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
            dependencies: ["CSDL2", "CPMurHash", "CTinyFileDialogs"],
            path: "./src",
            exclude: [
                "./platform/android",
//                "./platform/emscripten",
                "./platform/haiku",
                "./platform/switch",
                "./platform/vita",
                "./CAugustus.apinotes"
            ],
            sources: [
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
                "./window",
                "./version.c",
                "./CAugustus.swift"
            ],
            resources: [.copy("../assets")],
            publicHeadersPath: "./",
            cSettings: [
                .headerSearchPath("."),
                .headerSearchPath("../ext"),
                .headerSearchPath("../ext/png"),
                .define("EXCLUDE_MAIN", to: "1")
            ],
            linkerSettings: [
                .linkedLibrary("png"),
                .linkedLibrary("SDL2"),
                .linkedLibrary("SDL2_Mixer"),
                .linkedLibrary("expat"),
                .linkedLibrary("z")
            ]),

        .target(
            name: "CPMurHash",
            path: "./ext/PMurHash"
        ),

        .target(
            name: "CTinyFileDialogs",
            path: "./ext/tinyfiledialogs"
        ),
        
        .systemLibrary(
            name: "CSDL2",
            path: "./swift/Modules/CSDL2",
            pkgConfig: "sdl2",
            providers: [
                .brew(["sdl2"]),
                .apt(["libsdl2-dev"])
            ]
        ),
    ],
    cLanguageStandard: .gnu99
)
