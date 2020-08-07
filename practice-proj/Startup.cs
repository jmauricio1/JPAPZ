using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(practice_proj.Startup))]
namespace practice_proj
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
