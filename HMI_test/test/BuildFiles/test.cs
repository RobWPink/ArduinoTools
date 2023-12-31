using System.Collections;
using System;
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;
using System.Reflection;
using System.IO;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Threading;
using Core.Api.Application;
using Core.Api.Attributes;
using Core.Api.Service;
using Core.Api.Tools;
using Core.Api.Utilities;
using Neo.ApplicationFramework.Utilities;
using Core.Engine.Application;
using Neo.ApplicationFramework.Attributes;
using Neo.ApplicationFramework.Common;
using Neo.ApplicationFramework.Common.Keyboard;
using Neo.ApplicationFramework.Common.Runtime;
using Neo.ApplicationFramework.Common.TypeConverters;
using Neo.ApplicationFramework.Common.Utilities;
using Neo.ApplicationFramework.Interfaces;
using Neo.ApplicationFramework.Utilities.Lazy;
using Neo.ApplicationFramework.Utilities.Measurement;
using Neo.ApplicationFramework.Storage.Settings;
using Neo.ApplicationFramework.Tools.Runtime;
using Neo.ApplicationFramework.Tools.Storage;

[assembly: AssemblyVersion("2.50.73.0")]
[assembly: NeoDesignerVersion("2.50.73.0")]

namespace Neo.ApplicationFramework.Generated
{
    public class Globals : GlobalsBase
    {
        private static readonly log4net.ILog m_Log = log4net.LogManager.GetLogger(typeof(Globals));

        static Globals()
        {
            
        }

        public Globals() 
            : base(CreateToolManager())
        {
            m_ProjectSettings.MainScreenTitle = "test";
            m_ProjectSettings.Topmost = true;
            m_ProjectSettings.StartupLocation = new Point(0, 0);
            m_ProjectSettings.MaximizeOnStartup = false;
            m_ProjectSettings.UseWideScrollbars = false;
            m_ProjectSettings.MainScreenSize = new Size(800,480);
            m_ProjectSettings.BorderStyle = ScreenBorderStyle.ThreeDBorder;
            m_ProjectSettings.InputDelay = 2000;
            m_ProjectSettings.IsOnScreenKeyboardEnabled = true;
            m_ProjectSettings.OnScreenKeyboardSizeProperties = new OnScreenKeyboardSizeProperties(false, true, 100, false, false, 50);
            m_ProjectSettings.KeyboardLayoutName = "US";
            m_ProjectSettings.TerminalGroup = TerminalGroup.Default;
            List<IStorageProviderSetting> storageProviderSettingsList = new List<IStorageProviderSetting>() {
                new ProjectStorageProviderSetting("BackupAtStartup", false), new ProjectStorageProviderSetting("MaxSize", 0), 
            };
            m_ProjectSettings.StorageProviderSettings = new LocallyHostedProjectStorageProviderSettings("SQLite Database", storageProviderSettingsList, "");
            m_ProjectSettings.EnableWatchDogSettings = false;
            m_ProjectSettings.WatchDogTimeOut = 120;
            m_SystemSettings.AutomaticallyTurnOfBacklight = false;
            m_SystemSettings.BacklightTimeout = 900;    
            m_SystemSettings.KeepBacklightOnIfNotifierWindowIsVisible = false;
            Dictionary<ComPort, PortMode> comPortModes = new Dictionary<ComPort, PortMode>();
            comPortModes.Add(ComPort.COM1, PortMode.Nonconfigurable); comPortModes.Add(ComPort.COM2, PortMode.rs422);                            
            m_SystemSettings.ComPortModes = comPortModes;                            
            m_SystemSettings.KeyBeep = true;
            m_SystemSettings.TimeZoneDisplayName = "";
            m_SystemSettings.TimeZoneId = -1;
            m_SystemSettings.RegionLCID = 0;
            m_SystemSettings.AdjustForDaylightSaving = true;
            m_SystemSettings.FtpServerEnabled = false;
            m_SystemSettings.FtpServerFriendlyNamesEnabled = false;
            m_SystemSettings.FtpServerAllowAnonymous = false;
            m_SystemSettings.FtpServerSdCardAccess = false;
            m_SystemSettings.FtpServerUsbAccess = false;
            m_SystemSettings.FtpServerDefaultDir = @"";
            m_SystemSettings.NTLMUser = @"";
            m_SystemSettings.NTLMPassword = @"";
            m_SystemSettings.VncServerEnabled = false;
            m_SystemSettings.VncTcpPort = 5900;
            m_SystemSettings.VncHttpTcpPort = 5800;
            m_SystemSettings.VncViewOnlyPassword = @"";
            m_SystemSettings.VncFullAccessPassword = @"";
            m_SystemSettings.VncActiveConnectionNotification = false;
            m_SystemSettings.IsKeyPanel = false;
            m_SystemSettings.IsHeadless = false;
            m_SystemSettings.AlarmButtonShowScreenTarget = @"";
            m_SystemSettings.ScreenRotationAngle = 180;
            m_SystemSettings.BeShellMenuPassword = @"";
            m_SystemSettings.ProjectGuid = new Guid("8cc22d85-62f6-458e-8d2e-3c3d0452fe78");
#if VNEXT_TARGET
#pragma warning disable CS0162 // Unreachable code detected
            Controls.Controls.OffscreenGraphics.SetDefaultSize(m_ProjectSettings.MainScreenSize, !true);
#pragma warning restore CS0162 // Unreachable code detected
#endif
        }
        
        
        private static IToolManager CreateToolManager()
        {
            string executablePath = typeof(Globals).Module.FullyQualifiedName;            
            // take simulation into account
            var coreApplication = Environment.OSVersion.Platform != PlatformID.WinCE ? (ICoreApplication)new CoreApplication(true, executablePath) : (ICoreApplication)new CoreApplicationCe();
            IToolManager toolManager = new ApplicationEngineCe().CreateToolManager(true, coreApplication, Path.Combine(coreApplication.StartupPath, "Modules.cfgtool"));
            return toolManager;
        }
            

        
       

        /// <summary>
        /// Neo generated code - do not modify
        /// the contents of this method(s) with the code editor.
        /// </summary>        
                    public static IPrinterDevice Printer1
                    {
                        get
                        {
                            IDeviceManagerServiceCF deviceManagerService = ServiceContainerCF.GetService<IDeviceManagerServiceCF>();
                            return deviceManagerService.GetOutputDevice<IPrinterDevice>();
                        }
                    }           
                    public static IDataSourceContainerAdapter Controller1
                    {
                        get
                        {
							return GlobalReferenceService.Value.GetObject<Controller1>("Controller1").Adapter;
                        }
                    }           
                    public static AlarmServer AlarmServer
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<AlarmServer>("AlarmServer");
                        }
                    }           
                    public static LicenseRootComponent LicenseRootComponent
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<LicenseRootComponent>("LicenseRootComponent");
                        }
                    }           
                    public static MultipleLanguages MultipleLanguages
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<MultipleLanguages>("MultipleLanguages");
                        }
                    }           
                    public static Tags Tags
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<Tags>("Tags");
                        }
                    }           
                    public static Expressions Expressions
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<Expressions>("Expressions");
                        }
                    }           
                    public static Security Security
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<Security>("Security");
                        }
                    }           
                    public static ProjectConfiguration ProjectConfiguration
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<ProjectConfiguration>("ProjectConfiguration");
                        }
                    }           
                    public static SntpClientRootComponent SntpClientRootComponent
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<SntpClientRootComponent>("SntpClientRootComponent");
                        }
                    }           
                    public static IScreenAdapter Screen1
                    {
                        get
                        {
                            return GlobalReferenceService.Value.GetObject<Screen1>("Screens.Screen1.Default").Adapter;
                        }
                    }   
#if VNEXT_TARGET
        [STAThread]
#else
        [MTAThread]
#endif
        static void Main(string[] args)
        {
            Thread.CurrentThread.Name = "NeoMainThread";
            
            InitializeBeHwApiLog();
            
            
            
            UserStartupMessage.SendUserStartupMessageToBeijerShell("Loading Files");
            if (!StopWatchCF.Silent)
                StopWatchCF.Send("Starting Project");
            StopWatchCF.SetTimestamp("***** Project Startup Time *****");
            while (ProcessExplorer.WaitForAttachDebugger)
            {
                Thread.Sleep(1000);
            }
            IsCompiledForCE = true;
            IsCompiledForDesktopWindowsPanel = false;
#if VNEXT_TARGET

            if (Common.Brand.BrandConstants.BrandName != "vNext")
            {
#pragma warning disable CS0162 // Unreachable code detected
                DialogResult result = MessageBox.Show("vNext source code is used for non-vNext brand. Proceed?", "Mixed mode detected", MessageBoxButtons.OKCancel);
                if (result != DialogResult.OK) return;
#pragma warning restore CS0162 // Unreachable code detected
            }
#endif

            Instance = new Globals();
        	if (!Instance.CheckIfApplicationCanRun())
				return;

            string executingAssemblyName = Assembly.GetExecutingAssembly().FullName;
            string executablePath = typeof(Globals).Module.FullyQualifiedName;
            Instance.Go(executingAssemblyName, executablePath, args, new string[]{"SntpClientRootComponent","ProjectConfiguration","Security","Expressions","Tags","MultipleLanguages","LicenseRootComponent","AlarmServer","CloudConfiguration","Controller1","ProjectImages"}, new string[]{}, () => Screen1);
        }

    }
}