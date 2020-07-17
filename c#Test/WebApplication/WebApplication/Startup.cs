using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
// using Microsoft.Extensions.Options;
using MySql.Data.EntityFrameworkCore.Extensions;

namespace WebApplication
{
    public class Startup
    {
        public IConfiguration _Configuration { get; }
        // This method gets called by the runtime. Use this method to add services to the container.
        // For more information on how to configure your application, visit https://go.microsoft.com/fwlink/?LinkID=398940
        public Startup(IConfiguration configuration  )
        {
            _Configuration = configuration;
        }
                       //配置服务         这是一个服务容器
        //这是先被调用
        public void ConfigureServices(IServiceCollection services)
        {
            var db = new  BloggingContext(  );
            var blog = new Blog (  123 , "ryan"  );
            db.Blogs.Add(blog);
            db.SaveChanges();

            // var blogs = db.Blogs;
            // Console.WriteLine( blogs );

            // Console.WriteLine( _Configuration["MySqlConnectionString"] );
            // services.AddDbContext<BloggingContext>(options =>
            // {
            //     options.UseMySQL(_Configuration["MySqlConnectionString"]);
            // } );
        }

        //每个 Use 扩展方法将一个或多个中间件组件添加到请求管道
        //请求管道中的每个中间件组件负责调用管道中的下一个组件，或在适当情况下使链发生短路
        //                       配置请求管道             当前应用的环境
        //后被调用
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }
            
            app.UseRouting();

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapGet("/", async context => { await context.Response.WriteAsync("Hello World!"); });
            });
        }
    }
}