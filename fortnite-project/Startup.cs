using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(fortnite_project.Startup))]
namespace fortnite_project
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
