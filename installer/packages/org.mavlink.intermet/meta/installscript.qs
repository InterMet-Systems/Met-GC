function Component()
{
    // Default behavior for Component
}

Component.prototype.createOperations = function()
{
    component.createOperations();
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut",
            "@TargetDir@/CustomQGroundControl.exe",
            "@StartMenuDir@/Met-GC.lnk",
            "workingDirectory=@TargetDir@",
            "iconPath=@TargetDir@/CustomQGroundControl.exe", "iconId=0",
            "description=Open Met-GC App"
        );

        component.addOperation("CreateShortcut", 
            "@TargetDir@/CustomQGroundControl.exe",
            "@DesktopDir@/Met-GC.lnk",
            "workingDirectory=@TargetDir@",
            "iconPath=@TargetDir@/CustomQGroundControl.exe", "iconId=0",
            "description=Met-GC"
        );
    }
}