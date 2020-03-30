/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <artist/resources.hpp>
#include <mutex>

namespace cycfi::artist
{
   __attribute__((weak)) void init_paths()
   {
   }

   std::vector<fs::path> resource_paths;
   std::mutex resource_paths_mutex;

   void add_search_path(fs::path const& path, bool search_first)
   {
      std::lock_guard<std::mutex> guard(resource_paths_mutex);
      if (search_first)
         resource_paths.insert(resource_paths.begin(), path);
      else
         resource_paths.push_back(path);
   }

   namespace
   {
      struct resource_setter
      {
         resource_setter()
         {
            init_paths();
         }
      };
   }

   fs::path find_file(fs::path const& file)
   {
      static resource_setter init_resources;

      fs::path full_path;
      if (fs::path(file).is_absolute())
      {
         if (fs::exists(file))
            full_path = file;
      }
      else
      {
         std::lock_guard<std::mutex> guard(resource_paths_mutex);
         for (auto const& path : resource_paths)
         {
            fs::path target = fs::path(path) / file;
            if (fs::exists(target))
            {
               full_path = target.string();
               break;
            }
         }
      }
      return full_path;
   }
}