# ARK-4 e/CFW for the PSP and PS Vita.

New, updated, improved and modern `Custom Firmware` for the `PSP` and `PS Vita`'s `ePSP`.
Simple to use and full of unique features, `ARK CFW` aims at keeping the `PSP` experience fresh. Being a successor to `PRO` and `ME`,
`ARK` is now the most feature-complete `CFW` for the `PSP`, having all features from classic `CFW`
as well as unique and exclusive new features not found anywhere else.

### Table of Contents (Quick Links)
<<<<<<< HEAD
  * [FEATURES](#features)
  * [INSTALLATION](#installation)
    * [Manual installation  ](#manual-installation)
  * [CUSTOMIZATION](#customization)
    * [Custom Themes](#custom-themes)
  * [Other](#other)
=======
  

<br/>
<a style="font-weight: bold; font-size:18px; text-decoration: underline;" href="https://github.com/PSP-Archive/ARK-4/wiki">→ ARK-4 WIKI (Recommended for more in-depth Instructions) ←</a>
<br>
<br>


<a style="font-size: 18px;" href="https://discord.gg/bePrj9W">Join the PSP Homebrew Community Discord</a>
<br>
<label style="text-decoration: underline; font-size: 14px;">We are located in the <b>#ark-cfw channel</b></label>
<br>
<br>


  * [FEATURES:](#features)
  * [INSTALLATION](#installation)
      - [Compiling ARK ( For Developers )](#compiling-ark--for-developers-)
      - [On PSP](#on-psp)
          + [Online PSP Installer](#online-psp-installer)
          + [Initial installation  ](#initial-installation)
          + [Permanent CFW via cIPL](#permanent-cfw-via-cipl)
        * [Permanent CFW via Infinity](#permanent-cfw-via-infinity)
        * [Full Flash Installation](#full-flash-installation)
        * [Time Machine and Despertar del Cementerio](#time-machine-and-despertar-del-cementerio)
      - [On PS Vita](#on-ps-vita)
        * [Standalone](#standalone)
        * [Adrenaline](#adrenaline)
      - [Legacy Game Exploits (PSP & Vita)](#legacy-game-exploits-psp--vita)

  * [UPDATING ARK](#update-ark)

  * [RECOVERY](#recovery)
      - [Recovery Menu](#recovery-menu)
      - [Vanilla Mode](#vanilla-mode)
      - [Official Firmware Mode](#official-firmware-for-psp-permanent-installations)
      - [Pandora/BaryonSweeper](#pandora-or-baryon-sweeper-for-psp)

  * [CUSTOMIZATION](#customization)
      - [Advanced VSH Menu Options](#advanced-vsh-menu-options)
      - [Installing Plugins](#installing-plugins)
      - [Configuration and Settings](#configuration-and-settings)
      - [Custom Launcher](#custom-launcher)
      - [Custom Themes](#custom-themes)
      - [Other Launchers](#other-launchers)
  * [Other](#other)
      - [History](#history)
      - [Changelog](#changelog)
      - [Credits](#credits)
      - [Warnings](#warnings)
>>>>>>> refs/remotes/origin/main

## FEATURES:

- `Core` system heavily updated from traditional CFW with new exclusive features.

- `Inferno 2` Driver compatible with all formats (`ISO`, `CSO`, `ZSO`, `JSO`, `CSOv2` and `DAX`).

- `Popcorn` controller for custom `PS1` games. Compatible with `PopsLoader` V3 and V4i.

- Built-in `No-DRM` engine `Stargate`, fixes many anti-CFW games. Compatible with `npdrm_free` and `nploader`.

- `Plugin` support for `PSP` games, `PS1` games and `VSH` (XMB), including the ability to enable and disable plugins `per-game`.

- `Region Free` playback of `UMD Video` on all PSP models. Change the region of your `UMD` drive on-the-fly.

- Compatible with all `PSP` models on firmwares `6.60` and `6.61`.

- Compatible with all `PS Vita` models on firmware `2.10` up to `3.74`, either official firmware or via `Adrenaline`.

- Compatible with `6.60` `Testing Tool` Firmware and `Testkit` Units.

- Compatible with `6.60` `Development Tool` Firmware and `Devkit` Units.

- Can be fully installed and booted on memory stick in compatible models via `Time Machine`.

- Can be used to unbrick compatible PSP models using `Despertar del Cementerio` in combination with a `Pandora` or `Baryon Sweeper`.

- `Minimalistic`: only 6 files installed on PSP flash, CFW extensions are installed on memory stick.

- Resistant to `soft-bricks`, easy to recover from bad configurations with a new and improved `Recovery` app.

- `Custom game launcher` with built-in game categories, file browser, `FTP` server and client, modernized look and more.

- Fully configurable via the `XMB`.

- Compatible with `PRO Online` and `Xlink Kai`.

- Compatible with Legacy Homebrew via `eLoader` and `Leda`. Compatible with the KXploit format.

- Compatible with `cIPL` and `Infinity 2` bootloaders for permanent CFW.

- `OTA` updates. Fully updateable via the internet.

![ARK Custom Firmware](.github/screenshots/xmb(10).png "ARK Custom Firmware")

![ARK Custom Firmware](.github/screenshots/xmb(11).png "ARK Custom Firmware")

![ARK Custom Firmware](.github/screenshots/pic_0016.bmp "ARK Custom Firmware")


## INSTALLATION

- Download the precompiled binaries from: https://github.com/PSP-Archive/ARK-4/releases/latest
- You can follow this video with instructions to install `ARK` on `PSP` via `Infinity` and/or on `PS Vita` via `Adrenaline`: https://youtu.be/bE8mw7RRqGo


#### Compiling ARK ( For Developers )
<p>

    Build script will allow you to use the correct SDK that ARK was built with.

- Docker container: `docker pull docker.io/krazynez/ark-4:latest`

<p><b>These are utlized either with cloning the repo or using the Docker container</b></p>

- Release: `./build.sh` 
- Debug: `./build.sh --debug`
- Manually: install the oldest possible SDK (ideally the one used to compile M33), then run `make`

Use `-h` or `--help` to show all available flags 

</p>

#### On PSP
<p>

###### Online PSP Installer
For an easy deployment of ARK on a PSP connected to the internet, you can follow this [video](https://www.youtube.com/watch?v=mopy1N57DlI)


###### Initial installation  
  
The instructions are as follows:
  
- Move or copy `ARK_01234` folder into `/PSP/SAVEDATA/` folder.
- Move or copy `ARK_Loader` folder into `/PSP/GAME/` folder.
- Launch `ARK Loader`. It will install ARK modules on PSP Flash and boot the CFW.
- At this point `ARK` will work as a `Live CFW`, meaning that `ARK Loader` will need to be run every time the console is turned off or rebooted.
- To convert `ARK` into a `Permanent CFW` you can use either `cIPL` or `Infinity`, along with the `Full Installer` for a complete permanent experience.

###### Permanent CFW via cIPL
<p>

  - `New cIPL`: works on `1g`, `2g` and `3g` models on `6.61`.
  - `Classic cIPL`: works on `Pandora` compatbile models (`1g` and early `2g`) on `6.60`, `6.61` or `6.60 Testing Tool`.
  - `DevTool cIPL`: works on `DTP-T1000` devkit units on `6.60 Development Tool` firmware.
  - cIPL will not install if not compatible, so no risk if running it even if you're unsure what specific model you're using - if not compatible, use `Infinity 2` instead.
  - Move or copy either `ARK_newIPL`, `ARK_classicIPL` or `ARK_Devtool_cIPL` folder to `/PSP/GAME/` and run the program.
  - Press the corresponding button in the installation page to install or remove the cIPL patch.
  - Warning: unlike classic cIPL, the new cIPL method can't be easily uninstalled. To revert to offical IPL, use ChronoSwitch to reinstall 6.61 OFW.

</p>

###### Permanent CFW via Infinity
<p>
  <b>*RECOMMNEDED*</b> If already using another CFW with Infinity < 2.0.5, use chronoswitch to reinstall 6.60/6.61 OFW (Offical Firmware). If you do not when launching Infinity it <em>can</em> just lock your PSP up causing Infinity to not work properly (not harmful, just not properly). Then proceed with intructions. You can still bi/tri boot your CFW afterwards. 

  - Works on all PSP models on 6.60 or 6.61 firmwares.
  - Copy or move the `EBOOT.PBP` (or `EBOOT_GO.PBP` renamed to `EBOOT.PBP` if using a PSP Go) from the `Infinity` folder found in the ARK download into `/PSP/GAME/UPDATE`.
  - Run the`Infinity` app using Official Firmware to run the initial installation. If you previously had and older Infinity installed when prompted to update please do, as our Infinity version includes the ARK patches to autoboot.
  - Run `Infinity` a second time to configure autoboot by selecting ARK within the Infinity app. Run the ARK CFW again to activate. ARK will now be automatically activated on boot up.

</p>

###### Full Flash Installation
<p>

  - This allows you to install and use all of ARK's features on the console's internal flash memory, allowing you to entirely remove the `ARK_01234` savedata folder or memory stick.
  - Copy `ARK_Full_Installer` to `/PSP/GAME/` and run it from `ARK`. It will install some extra files into the console's flash.
  - This installation will make use of `Classic Recovery Menu` when the regular one is not available. The minimalistic `PRO Shell` is used in place of the `Custom Launcher`.
  - When no savedata folder is available the default ARK path used to store settings and other Custom Firmware files will be `ms0:/SEPLUGINS/`.

</p>

###### Time Machine and Despertar del Cementerio
<p>

  - `Time Machine` allows to boot the `6.61` firmware and `ARK` entirely from the Memory Stick.
  - `Despertar del Cementerio` allows to revive a bricked PSP when used in combination with a `Pandora` or `Baryon Sweeper`.
  - To install `DC-ARK` you must first format the memory stick leaving enough space for the boot sector. You can use `PSP Tool` to do this.
  - You also need to be running a `CFW` to install `DC-ARK` (ARK itself or any other).
  - Copy the `ARK_DC` folder to the `/PSP/GAME/` folder and run the installer from the `XMB`.
  - Follow the instructions to install DC-ARK and create a magic memory stick.
  - On compatible models, use `Advanced VSH Menu` to create a `Pandora` battery.
  - Use a `Pandora` or `Baryon Sweeper` in combination with your newly created `Magic Memory Stick` to boot up `Despertar del Cementerio`.
  - From here you can either boot ARK from memory stick, install 6.61 Firmware with ARK on the Nand or install 6.61 Official Firmware.
  - Note that installing 6.61 firmware with ARK requires a cIPL-compatible PSP (1K and early 2K).

</p>

</p>

#### On PS Vita
<p>

###### Standalone
<p>

  - Works on Firmware 3.60 up to 3.74, requires Henkaku/h-encore or any native hack.
  - Download and install <a href="https://github.com/LiEnby/NoPspEmuDrm/releases">NoPspEmuDrm by SilicaAndPina</a> (you can use <a href="https://github.com/ONElua/AutoPlugin2/releases/latest">AutoPlugin II</a>).
  - Copy `FasterARK.vpk` from `Vita/Standalone/` folder anywhere on your vita and install using `VitaShell`. 
  - Open `FasterARK` and wait for the install process to finish. An `ARK` bubble will appear in `Live Area`.
  - Once `ARK` is installed, you can delete `FasterARK`.
  - To use right analog stick (i.e. gta_remastered plugin): https://github.com/rereprep/ArkRightAnalog
  - To `exit` from a game or homebrew back to the `custom launcher`, press `L+R+Down+Start`. Works on `PSP` too.
  - NOTE: Some features are not available in standalone installations, mainly the official Sony `XMB` and `Force Extra RAM` setting.
  - NOTE: There are limitations in the playback of `PS1` games, mostly related to audio.
  - If you want to have an `ARK` bubble that works on `Official Firmware` you must use `ChovySign`.

</p>


###### Adrenaline
<p>

  - Works on Firmware 3.60 up to 3.74, requires Henkaku/h-encore and `Adrenaline` (https://github.com/TheOfficialFloW/Adrenaline).
  - Install `ARK_01234` folder into `/PSP/SAVEDATA/` folder.
  - Install `ARK_Loader` folder into `/PSP/GAME/` folder.
  - Delete `K.BIN` from `ARK_Loader` folder. You can optionally copy `K.BIN` from `PSVita/Adrenaline` folder into `ARK_Loader` game folder for a bit faster loading.
  - Use `Adrenaline Bubbles Manager` to create an autoboot bubble for `ARK Loader`: https://github.com/ONElua/AdrenalineBubbleManager/releases
  - Note: this does not permanently modify `Adrenaline` in any way.

</p>


</p>

#### Legacy Game Exploits (PSP & Vita)
<p>

- This is mainly for `developers`.
- Considering the savedata exploit loads `H.BIN` from the savedata path.
- Copy every file from `ARK_01234` except `PARAM.SFO`, `SAVEDATA.BIN` and `K.BIN` (`ICON0.PNG` can also be ignored), into the hacked savedata folder.
- You need to have a `K.BIN` if you are running on an ancient Vita firmware (there's plenty of kernel exploit sources in ARK-2 and ARK-3 for reference).
- Run the game and trigger the exploit as normal, it should load ARK.
- If you have issues with stability, it might be necessary to run `freemem()` algorithm in the kernel exploit file (`K.BIN`).
  
</p>

#### Update ARK
<p>

There are three ways to update ARK:

  - Option 1: Use the `System Update` feature in the `XMB` or the `Network` tab in `Custom Launcher` to perform an `OTA` update. Requires your PSP/Vita to be connected to the internet.
  - Option 2: Copy the `UPDATE` folder to `/PSP/GAME/` and run it.
  - Option 3: Copy `ARK_01234` folder and (on PSP) run `ARK Loader` again to install new flash0 files. If running a `Full Installation` you will need to run the `Full Installer` again to flash the extra modules.

The `OTA` updater has the server URL stored in a file named `UPDATER.TXT` inside `ARK_01234`. This allows the user to change their update server if they wish to use a custom one. For example, by adding `/test` at the end of the URL will make it point to the `pre-release` server, allowing you to install the latest build of ARK synchronized with the last commit on the main branch (these release may be `unstable` so act with care).

</p>

## RECOVERY

There are various ways to recover from a bad installation, usually result of `bad configuration` or `misbehaving plugins`, which may lead to `crashes` and even `bricks`.

#### Recovery Menu
This option allows you to boot up a `Recovery App` with settings and plugins completely disabled to prevent issues. You can use this app to change settings, plugins and use a file browser for various recovery operations.

<p></p>

The `Recovery App` is installed on `Memory Stick` located at `/PSP/SAVEDATA/ARK_01234/RECOVERY.PBP` and can be changed to just about any homebrew in `PBP` format.

<p></p>

To load into the `Recovery App` you must hold the `R trigger` while turning on the `PSP` console or running `ARK Loader`. You can also do the same when running any of the `Bubbles` on `PS Vita`, either `Adrenaline` or `Standalone` (except for `ARK-X`).

<p></p>

When using a `Full Installation` on `PSP` and no `Recovery App` is available, `ARK` will load the `Classic Recovery Menu` from `flash0`, which includes `PRO Shell`, a minimalistic `File Manager` and `Launcher`.

<p style="font-weight:bold;">Classic Recovery</p>
<img src=".github/screenshots/classic_recovery_menu.jpg" width="450"></a>

<p style="font-weight:bold;">Pro Shell</p>
<img src=".github/screenshots/pro_shell.jpg" width="450"></a>

#### Vanilla Mode
If the `Recovery App` is unavailable, or for a better/easier diagnostics, you can run `ARK` in `Vanilla Mode`, which temporarily disables settings and plugins when running `ARK` or booting any game.

<p></p>

This will load the `XMB` as original as possible but you can still use features such as the `VSH Menu` or `XMB Control` (which will let you reconfigure all your settings and plugins), it also works for games.

<p></p>

To enable `Vanilla Mode` simply hold `select` and/or `start` during bootup or gameboot to disable settings and plugins respectively.

<p></p>

The effect of `Vanilla Mode` is temporary and goes away on the next game boot or reboot unless you enable it again.

#### Official Firmware (for PSP Permanent Installations)
For any `PSP` user that has a `Permanent` installation (i.e. `Infinity` or `cIPL`), you always have the option to boot the console in `Official Firmware` mode, which completely disables all `Custom Firmware` functionality until the next full reboot.

#### Pandora or Baryon Sweeper (for PSP)
If the console is `Bricked` and none of the above helps recovering the system, the last resort is to use a `Pandora Battery` or `Baryon Sweeper` in combination with a `Magic Memory Stick`.

<p></p>

You can find steps to install `Despertar del Cementerio` for `Pandora` models in this document.

<p></p>

For `Baryon Sweeper` users, you can use this tutorial: https://www.psx-place.com/threads/update-baryon-sweeper-unbrick-psp-1000-2000-3000-psp-slim-04g-07g-09g-psp-street-11g-model.32503/


## CUSTOMIZATION

#### Advanced VSH Menu Options
<p>

The default VSH menu packaged in `ARK_01234` is a simplified, easier to use version of classic VSH menus.
To have a more classic VSH menu with more advanced features you can select the `Advanced VSH Menu` from within the simplified VSH menu.

![Advanced VSH Menu](.github/screenshots/pic_0014.bmp "Advanced VSH Menu")

Some of the features available in Advanced VSH Menu include:

- Change USB Device mount (Memory Stick, Flash, UMD).
- Protect Flash in USB Device mount.
- View available ISO drivers.
- Mount UMD Video ISO.
- Change Foreground/Background VSH Menu colors.
- Convert battery from normal to pandora and viceversa.
- Activate flash and WMA playback.
- Swap X/O buttons.
- Delete hibernation (PSP Go paused game).
- Convert classic plugins to the new ARK format.
- Boot Random ISO.

And more.

Installing on PSP Flash:

`WARNING`: for advanced users only, do not attempt this if you're not familiar with the PSP flash.

By default, ARK's VSH Menu is installed on the Memory Stick (in `/PSP/SAVEDATA/ARK_01234/VSHMENU.PRX`).
This has the limitation that you won't be able to access VSH menu without a memory stick.
If you want to permanently install VSH Menu you need to copy `VSHMENU.PRX` to somewhere on your computer and rename it to `ark_satelite.prx`,
which you can then copy to PSP's `flash0:/vsh/module/`, you can use the VSH Menu itself to enable flash0 via USB. The final path should be `flash0:/vsh/module/ark_satelite.prx`.
You can also achieve the same result by using the `Full Installer`.

`NOTE`: even if you install VSH Menu on flash0, the one installed on Memory Stick takes precedence in loading.

</p>

#### Installing Plugins
<p>
  
The easiest method to install a plugin is to simply copy its `.prx` (and other files/folders the plugin needs) to its default installation folder (typically `/SEPLUGINS/` folder) and navigate to it using the `File Browser` (built into Recovery Menu and Custom Launcher). Upon opening the `.prx` file, you will be given the options to select the runlevel, or type the game ID, where the plugin loads.

![File Browser Plugin Installer](.github/screenshots/pic_0015.png "File Browser Plugin Installer")

From there you can use the `XMB` or `Recovery Menu` to configure or remove your installed plugins.

![XMB Plugins Menu](.github/screenshots/xmb(2).png "XMB Plugins Menu")

![Recovery Plugins Menu](.github/screenshots/pic_0002.png "Recovery Plugins Menu")

Alternately, you can manually install plugins by creating a file called PLUGINS.TXT in the /SEPLUGINS/ folder and/or ARK's savedata folder.

If coming from PRO/ME you can Import them from the `Advanced VSH Menu` section.

To install plugins use the comma-separated format (CSV).
Where the header is: runlevel, path, switch.
A few samples:
- game, ms0:/seplugins/cwcheat/cwcheat.prx, enabled
- pops, ms0:/seplugins/cdda_enabler.prx, 1
- vsh, ms0:/seplugins/cxmb.prx, true
- ULUS10041, ms0:/seplugins/lcscheatdevice.prx, on

You can enable plugins on more than one game:
- ULUS10041 ULES00502, ms0:/seplugins/cheatdevice_remastered.prx, on

You can use the following keywords to enable a plugin:
- 1
- on
- true
- enabled
- Anything else disables the plugin

You can use the following keywords to tell ARK when the plugin loads:
- `all`/`always`: if either of these keywords are used, the plugin will always load.
- `psp`/`umd`: plugin should only load on retail games (UMD/ISO/PSN).
- `homebrew`: plugin should only load on homebrews.
- `game`: plugin can load on both retail games and homebrews.
- `psx`/`ps1`/`pops`: plugin only loads in PSX games.
- `xmb`/`vsh`: plugin only loads in the XMB.
- `launcher`: use this if the plugin should only load in the custom launcher.
- `game ID`: if you specify a game ID (i.e. `SLUS000000`), then the plugin will only load on that game.

You can also disable a plugin on certain games where they might be problematic.
To do so, just add a disable line for the specific game ID after the enable line.
For example, enable cwcheat on all retail games except for GTA LCS (US) and GTA VCS (EU).
- psp, ms0:/seplugins/cwcheat/cwcheat.prx, on
- ULUS10041 ULES00502, ms0:/seplugins/cwcheat/cwcheat.prx, off

Some noteworthy plugins that are compatible with ARK include (but not limited to):
- CXMB.
- Leda.
- PopsLoader V3 and V4i.
- Custom Firmware Extender.
- PSPLink.
- GTA LCS and VCS cheadevice (including the remastered version).
- CWCheat.
- pspstates kai.
- XMB Item Hider v1.3-r3
- DayViewer.
- Categories Lite.
- CDDA Enabler.
- PRO Online.
- PSP 3D.
- ZeroVSH Patcher.


</p>

#### Configuration and Settings
<p>

You can use the XMB and/or the Recovery Menu to easily handle CFW settings. However if you prefer you can also manually handle the settings yourself.

![XMB Custom Firmware Settings](.github/screenshots/xmb(1).png "XMB Custom Firmware Settings")

![Recovery Custom Firmware Settings](.github/screenshots/pic_0001.png "Recovery Custom Firmware Settings")

You can create a SETTINGS.TXT file using the same format as PLUGINS.TXT to enable/disable some CFW functionality on different parts of the system.
Configuration settings you can use in ARK include:

- `overclock`: use this for better performance at the expense of battery time. Sets CPU/BUS speed to 333/166.
- `powersave`: use this for better battery life at the expense of performance. Sets CPU/BUS speed to 133/66.
- `usbcharge`: enables USB charging wherever you want.
- `launcher`: replaces the XMB with a custom menu launcher.
- `disablepause`: disables the pause game feature on PSP Go.
- `highmem`: enables high memory on models above 1K.
 You should only use this on homebrew runlevel as retail games were not meant to use the extra memory,
 and this can cause issues with cheat devices or other plugins that expect games to have their data at specific memory addresses.
 - `infernocache`: enables cache for Inferno driver, improving performance of some games.
 - `oldplugin`: enables old plugins support on PSP Go (redirects `ms0` to `ef0`).
 - `skiplogos`: skips the coldboot and gameboot logos.

You can use the same runlevels as used in plugins to tell ARK when the settings take effect (all/always, umd, homebrew, game, pops, vsh).

For example, you can overclock to highest CPU speed like this:
- always, overclock, on

Another example, overclock only on games, use powersaving on VSH:
- game, overclock, on
- vsh, powersave, on

This also allows you to enable settings on specific games:
  - ULUS01234, overclock, on
  - ULES01234, powersave, on
  
</p>

<p>

#### Custom Launcher
  
ARK comes prepacked with a very powerful launcher with a built-in file browser and highly customizable.

![Launcher Game Menu](.github/screenshots/pic_0000.png "Launcher Game Menu")

Some of its features include:
  
  - Playback of ISO and all CSO formats with PMF video preview.
  
  - Playback of UMD game discs.
  
  - Categorized and organized game menu by PSP Games, PSP Homebrew and PS1 Games.
  
  - Ability to scan savedata folders for games.
  
  - Compatibility with old VHBL, ARK-2 and TN-CEF file names and folder paths.
  
  - Ability to copy, move or delete entire folders.
  
  - File browser has built-in FTP client, allowing you to browse and copy files from another PSP.
  
  - FTP server and client can run simultaneously.
  
  - Ability to mount UMD Video ISOs using the file browser.

  - Ability to extract .zip files (up to highest compression) and .rar files (standard compression).
  
  - Ability to edit text files (.txt, .cfg or .ini).
  
  - Ability to install Plugins via the file browser.
  
  - Different background animation effects.
  
  - And more.

![Launcher File Browser](.github/screenshots/pic_0017.png "Launcher File Browser")

  
You can however change it to whatever you please. You can change the theme used by both the custom launcher and recovery menu by replacing THEME.ARK with your own.

<p>

<<<<<<< HEAD
## Custom Themes
=======
###### Custom Themes
>>>>>>> refs/remotes/origin/main
You can install themes within Custom Launcher (and Recovery Menu). Just place the `themes` folder anywhere on your PSP and use the file browser in the Custom Launcher to select which theme (`THEME.ARK`) you would like to install. By selecting it a submenu will pop up asking to install it or to preview the theme without installing.

<i>Orbs are animations and not part of the actual Themes </i>

Theme: ARK_Revamped

![ARK_Revamped](.github/wallpapers/ARK_Revamped.png "ARK_Revamped")

Theme: Red 

![Red](.github/wallpapers/red.png "Red")

Theme: Ubuntu 

![Ubuntu](.github/wallpapers/Ubuntu.png "Ubuntu")

Theme: Peace Walker 

![Peace Walker](.github/wallpapers/peacewalker.png "Peace Walker")

Theme: Matrix

![Matrix](.github/wallpapers/matrix.png "Matrix")

Theme: Material Dark

![Material Dark](.github/wallpapers/materialdark.png "Material Dark")

Theme: GX Classic

![GX Classic](.github/wallpapers/gxclassic.png "GX Classic")

Theme: Jurassic Park

![Jurassic Park](.github/wallpapers/Jurassic_Park.png "Jurassic Park")

Theme: Classic

![Classic](.github/wallpapers/classic.png "Classic")

Theme: Blue 2

![Blue 2](.github/wallpapers/blue2.png "Blue 2")

Theme: Blue

![Blue](.github/wallpapers/blue.png "Blue")

Theme: Black

![Black](.github/wallpapers/black.png "Black")

Theme: BadgerOS_Sprunk

![BadgerOS_Sprunk](.github/wallpapers/badgerOS_sprunk.png "BadgerOS_Sprunk")

Theme: BadgerOS

![BadgerOS](.github/wallpapers/badgerOS.png "BadgerOS")

Theme: CyanogenPSP

![CyanogenPSP](.github/wallpapers/CyanogenPSP.png "CyanogenPSP")

Theme: Windows 7

![Windows7](.github/wallpapers/Windows7.png "Windows7")

Theme: Windows XP

![WindowsXP](.github/wallpapers/WindowsXP.png "WindowsXP")

Theme: Yokai

![Yokai](.github/wallpapers/yokai.png "yokai")




###### Other Launchers
<p>

Aside from the default launcher provided, there have been many  other custom launchers created by scene members, some better looking, some with more features, some more simpler, but all of them with personality, dedication and love from the community.

Here is a list of all popular menus for ARK:

- ONEMenu by gdljjrod: https://github.com/ONElua/ONEmenu/releases

- vMenu by neur0n: http://www.mediafire.com/file/7acb5mhawx4gr9t/vMenu_ARK.7z/file

- yMenu by wth/yosh: https://docs.google.com/uc?export=download&id=0B0kWUCdtGmJwLUhRUlNJSWhMWVE

- gMenu by gbot: http://www.mediafire.com/file/oou5490qc99vr7d/gmenuARK.rar/file

- 138Menu by gbot: https://wololo.net/talk/viewtopic.php?f=53&t=33511

- pyMenu by Acid_Snake: https://wololo.net/talk/viewtopic.php?t=21942

You can find a collection here: https://github.com/PSP-Archive/ARK-Launchers

Note: some of these menus have not been updated or supported by their developers in a while, they may not work well with modern ARK or real PSP hardware.
</p>

</p>


## Other

#### History
Despite being a relatively new `Custom Firmware` for the `PSP`, `ARK` has quite a history that goes back to the early days of the `PS Vita` scene.

`ARK` is a `CFW` that started as a port (more like rewrite) of `PRO CFW` to the `PS Vita` (named `PROVITA`) created by the original `Team PRO` members (`Coldbird`, `Liquid Snake` and `Neur0n`).
After the original team left, the source code of `PROVITA` was handed over to me (`Acid_Snake`) and my long time scene friend `qwikrazor87`.

We quickly began a huge process of rewriting and restructuring code, more specifically a much more robust dynamic patching algorithms that would work on any 6.6X based firmware (including all Vita's ePSP firmwares). Thus `ARK-2` was born.

Soon after, qwik, thefl0w and I began working on `PSX exploits`, which resulted in `TN-X` and `ARK-3` (never publicly released).

Because the original `PRO CFW` hasn't been updated or maintained in a while, and it has become a little bloated and hard to work with, I decided to start working on porting `ARK` to the `PSP` since the core elements of the `CFW` are compatible with `PSP` `6.60` and `6.61` with minor changes.

After lots of work getting the same `ARK` binaries to properly work on both PSP and Vita, I am proud to announce that the release of `ARK-4` is finally here!


#### Changelog

- `ARK-1`: original port/rewrite of `PRO CFW` for the `PS Vita`. Codenamed `PROVITA`. Source code can be found here: https://github.com/PSP-Archive/ARK-1-PROVita-
- `ARK-2`: dynamic patching allows it to work with most of `PS Vita` firmwares. Source code can be found here: https://github.com/PSP-Archive/ARK-2
- `ARK-3`: device-specific runtime allows `ARK` to run in multiple scenarios (`ePSP` and `ePSX`). Source code can be found here: https://github.com/PSP-Archive/ARK-3
- `ARK-4`: ported to the original `PSP`. Huge amounts of improvements and fixes over previous versions.

`Note`: this is a simplified `changelog`, for a full version you can visit here: https://github.com/PSP-Archive/ARK-4/blob/main/CHANGELOG.md

#### Credits
<p>

- `Team PRO` (the original developers of ARK): `Coldbird`, `hrimfaxi` (aka. `Liquid Snake`) and `Neur0n`.

- `The Ancient Gods of the PSP Scene`: mathieulth, davee, Proxima, zecoxao, among other tinkerers.

- `qwikrazor87` for being such a genius and all his hard work with kernel exploits and ARK-2.
  
- `TheFl0w` (aka. `Total_Noob`) for his advancements and research in CFW development and overall contributions to the scene.

- `meetpatty` for his excellent work in fixing bugs and adding important features like cIPL and DevKit support as well as porting `Time Machine` and `Despertar del Cementerio`.

- `SilicaAndPina` for unlocking the full potential of the PS Vita's Official PSP emulator with such great tools like `ChovySign`, `NoPspEmuDrm` and `ps1cfw_enabler`.

- `Codestation` for his incredible work improving CSO speeds and creating the ZSO format.

- `Krazynez` for his amazing work on `Advanced VSH Menu` and other bugfixes and features.

- `pyroesp` for his excellent work improving `VSH Menu` and refactoring code.

- `TheSubPlayer` for all the wonderful themes made for the custom launcher.

- `UnkownBrackets` (maxcso) for his help understanding the DAX format and Inferno speed hacks as well as creating the CSOv2 format.

- `Zer01ne`, `noname120`, `astart` and other devs that have blessed me with their knowledge and wisdom.

- `Zecoxao` for his great work creating dumpers that would allow us to archive rare firmwares.

- `balika` for his research in porting M33 to modern firmware that has helped improve compatiblity in ARK.

- `hrydgard` for the PMF player as well as being an inspiration for the custom launcher.

- Every other giant shoulder I am standing on.

</p>

#### Warnings
<p>

- ARK comes with no warranty whatsoever. It was designed to be noob-proof, however it is possible for the universe to create an even greater noob capable of using ARK to destroy the Earth (or his PSP). I cannot be held responsible for this.

- ARK may cause ejectile malfunction if your hard drive is not hard enough.

- If this software malfunctions, you can turn it off and on again.
</p>
