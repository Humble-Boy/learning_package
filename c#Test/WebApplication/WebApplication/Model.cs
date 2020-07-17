using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace WebApplication
{
    
    public class  BloggingContext : DbContext
    {
        private readonly string _connectionString;
        public DbSet<Blog> Blogs { get; set; }
        // public DbSet<Post> Posts { get; set; }

        public BloggingContext(  )
        {
          
        }
        
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder
                .UseMySQL("server=localhost;user=root;password=feng123123;database=newTest", builder => builder.CommandTimeout(6000));
        }

        // protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        // {
        //     optionsBuilder.UseMySQL(
        //         @"Server=(localdb)\mssqllocaldb;Database=Blogging;Integrated Security=True");
        // }
        // protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        // {
        //     
        //     optionsBuilder.UseMySQL("Server=你的数据库地址;Database=ConsoleApp;User Id=你的数据库账号;Password=你的数据库密码;");
        // }
    }
    public class Blog
    {
        
        public Blog( int blogId ,string url )
        {
            BlogId = blogId;
            Url = url;
        }
        public int BlogId { get; set; }
        public string Url { get; set; }

        // public ICollection<Post> Posts { get; set; }
    }

    // public class Post
    // {
    //     public int PostId { get; set; }
    //     public string Title { get; set; }
    //     public string Content { get; set; }
    //
    //     public int BlogId { get; set; }
    //     public Blog Blog { get; set; }
    // }
}