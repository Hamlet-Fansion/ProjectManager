//
// Created by Hamlet on 2021/2/10.
//

#ifndef PROJECTMANAGER_FILE_H
#define PROJECTMANAGER_FILE_H

#include <filesystem>
#include <fstream>

using Path = std::filesystem::path;
using String = std::string;

namespace File {
    // 中文问题、子文件夹问题、其他父文件夹问题
    bool move_all(const String &path_from_name, const String &path_to_name) {
        // 子文件夹根本不管用
        Path path_from{path_from_name};
        Path path_to{path_to_name};
//        Path path_temp{path_from.parent_path()};
//        path_temp /= "temp";
        Path p;
        for (const auto &i:path_to) {
            p /= i.string();
            if (p == path_from)
                return false; // 暂不支持移动到当前文件夹的子文件夹
        }
//        std::filesystem::create_directory(pth); // 不管用
        if (std::filesystem::exists(path_from)) {
            if (!std::filesystem::exists(path_to)) { // !exists，代表不存在
                if (path_to.parent_path() != path_from.parent_path())
                    return false;
                std::filesystem::rename(path_from, path_to);
            } else {
                std::filesystem::copy(path_from, path_to, std::filesystem::copy_options::recursive);
                std::filesystem::remove_all(path_from);
            }
        }
        return true;
        // https://blog.csdn.net/woshi_hujunjun/article/details/77882227
    }

    Path create_file(const String &directory, const String &file_name, const String &extension) {
        Path p{directory};
        p /= (file_name + extension);
        std::ofstream file{p}; // 非常低级且弱智的方法
        return p;
    }

    void remove_file(const Path &file_path) {
        if (std::filesystem::exists(file_path))
            std::filesystem::remove(file_path);
    }

    Path search_readme(const String &directory) {
        Path dir{directory};
        if (std::filesystem::exists(dir / "README.txt")) // 优先.txt
            return dir /= "README.txt";
        else if (std::filesystem::exists(dir / "README.md"))
            return dir /= "README.md";
        return Path();
    }

    Path change_extension(const Path& file_path, const String &extension) {
        Path new_file_path{file_path};
        new_file_path.replace_extension(Path(extension));
        if (std::filesystem::exists(file_path))
            std::filesystem::rename(file_path, new_file_path);
        return new_file_path;
    }
}

#endif //PROJECTMANAGER_FILE_H
