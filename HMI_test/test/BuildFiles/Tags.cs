//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Neo.ApplicationFramework.Generated
{
	using Neo.ApplicationFramework.Tools.Actions;
	
	
	public partial class Tags : Neo.ApplicationFramework.Tools.OpcClient.GlobalController, Neo.ApplicationFramework.Interfaces.ISupportMultiLanguage
	{
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag Tag1;
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag Tag2;
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag Tag3;
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag bool1;
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag bool2;
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag bool3;
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag bool4;
		
		public Neo.ApplicationFramework.Tools.OpcClient.LightweightTag Tag4;
		
		public Neo.ApplicationFramework.Tools.OpcClient.PollGroup PollGroup1;
		
		public Neo.ApplicationFramework.Tools.OpcClient.PollGroup PollGroup2;
		
		public Neo.ApplicationFramework.Tools.OpcClient.PollGroup PollGroup3;
		
		public Neo.ApplicationFramework.Tools.OpcClient.PollGroup PollGroup4;
		
		public Neo.ApplicationFramework.Tools.OpcClient.PollGroup PollGroup5;
		
		public Tags()
		{
			this.InitializeComponent();
			this.ApplyLanguageInternal();
		}
		
		private void InitializeComponent()
		{
			this.InitializeObjectCreations();
			this.InitializeBeginInits();
			this.InitializeObjects();
			this.InitializeEndInits();
			this.ConnectDataBindings();
		}
		
		protected override void Dispose(bool disposing)
		{
			base.Dispose(disposing);
		}
		
		[System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
		public virtual void ConnectDataBindings()
		{
		}
		
		private void InitializeObjectCreations()
		{
			this.Tag1 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("Tag1", "Controller1.DataItem1", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_INTEGER2)), false, "", null);
			this.Tag2 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("Tag2", "Controller1.DataItem2", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_INTEGER2)), false, "", null);
			this.Tag3 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("Tag3", "Controller1.DataItem3", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_INTEGER2)), false, "", null);
			this.bool1 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("bool1", "Controller1.DataItem4", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_BIT)), false, "", null);
			this.bool2 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("bool2", "Controller1.DataItem5", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_BIT)), false, "", null);
			this.bool3 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("bool3", "Controller1.DataItem6", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_BIT)), false, "", null);
			this.bool4 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("bool4", "Controller1.DataItem7", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_BIT)), false, "", null);
			this.Tag4 = new Neo.ApplicationFramework.Tools.OpcClient.LightweightTag("Tag4", "Controller1.DataItem8", 500, ((Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE)(Neo.ApplicationFramework.Interop.DataSource.BEDATATYPE.DT_INTEGER2)), false, "", null);
			this.PollGroup1 = new Neo.ApplicationFramework.Tools.OpcClient.PollGroup();
			this.PollGroup2 = new Neo.ApplicationFramework.Tools.OpcClient.PollGroup();
			this.PollGroup3 = new Neo.ApplicationFramework.Tools.OpcClient.PollGroup();
			this.PollGroup4 = new Neo.ApplicationFramework.Tools.OpcClient.PollGroup();
			this.PollGroup5 = new Neo.ApplicationFramework.Tools.OpcClient.PollGroup();
		}
		
		private void InitializeBeginInits()
		{
			((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
		}
		
		private void InitializeEndInits()
		{
			((System.ComponentModel.ISupportInitialize)(this)).EndInit();
		}
		
		private void InitializeObjects()
		{
			this.LightweightTags.Add(this.Tag1);
			this.LightweightTags.Add(this.Tag2);
			this.LightweightTags.Add(this.Tag3);
			this.LightweightTags.Add(this.bool1);
			this.LightweightTags.Add(this.bool2);
			this.LightweightTags.Add(this.bool3);
			this.LightweightTags.Add(this.bool4);
			this.LightweightTags.Add(this.Tag4);
			this.PollGroup1.Interval = 500;
			this.PollGroup1.Name = "PollGroup1";
			this.PollGroup2.Interval = 500;
			this.PollGroup2.Name = "PollGroup2";
			this.PollGroup3.Interval = 500;
			this.PollGroup3.Name = "PollGroup3";
			this.PollGroup4.Interval = 500;
			this.PollGroup4.Name = "PollGroup4";
			this.PollGroup5.Interval = 500;
			this.PollGroup5.Name = "PollGroup5";
			this.PollGroups.Add(this.PollGroup1);
			this.PollGroups.Add(this.PollGroup2);
			this.PollGroups.Add(this.PollGroup3);
			this.PollGroups.Add(this.PollGroup4);
			this.PollGroups.Add(this.PollGroup5);
		}
		
		[System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
		private void ApplyLanguageInternal()
		{
			Neo.ApplicationFramework.Tools.MultiLanguage.MultiLanguageResourceManager resources = new Neo.ApplicationFramework.Tools.MultiLanguage.MultiLanguageResourceManager(typeof(Tags));
		}
		
		[System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
		void Neo.ApplicationFramework.Interfaces.ISupportMultiLanguage.ApplyLanguage()
		{
			this.ApplyLanguage();
		}
		
		[System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
		protected virtual void ApplyLanguage()
		{
			this.ApplyLanguageInternal();
		}
	}
}