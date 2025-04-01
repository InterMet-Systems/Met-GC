function Component()
{
    // Default behavior for Component
}

Component.prototype.createOperations = function()
{
    component.createOperations();
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@/CustomQGroundControl.exe", "@StartMenuDir@/Met-GC.lnk",
            "workingDirectory=@TargetDir@", "iconPath=%SystemRoot%/system32/SHELL32.dll",
            "iconId=2", "description=Open Met-GC App");
    }
}