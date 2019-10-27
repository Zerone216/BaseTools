#pragma once

#include "core/zs_stdc++.h"
#include "zs_json.hpp"

namespace zerone {

/**
 * @brief 参数解析时的动作
 *
 */
enum class zs_argv_action {
    store,          //保存值
    store_true,     //保存为true
    store_false,    // 保存为false
    count           // 保存数量
};

/**
 * @brief 参数选项
 *
 */
struct zs_argv_opt_t {
    std::string short_name{};    // 短名称，如:-i
    std::string long_name{};     // 长名称，如:--id
    std::string json_name{};     // 保存在json中的键名称，如：id
    zs_json_type type = zs_json_type::string;    // 参数类型（参加zs_json_type）
    bool required = true;                        // 是否必须
    zs_argv_action action{zs_argv_action::store};    // 动作
    zs_json default_value{};                         // 默认值
};

/**
 * @brief 参数解析类
 *
 */
class zs_argparser : public std::enable_shared_from_this<zs_argparser> {
   private:
    std::unordered_map<std::string, std::shared_ptr<zs_argparser>> sub_parsers_;
    std::vector<zs_argv_opt_t> position_arg_;
    std::vector<zs_argv_opt_t> none_position_arg__;
    std::pair<std::string, std::string> prefix_;
    std::string help_;

    zs_json parse_argv__(const std::vector<std::string> &argv) const;

    zs_argparser(const std::string &help = "",
                 const std::pair<std::string, std::string> &prefix = {"-",
                                                                      "--"});

   public:
    /**
     * 创建一个解析器对象
     * @param help 帮助信息（TODO 输出help信息）
     * @param prefix 前缀
     * @return 解析器对象
     */
    static std::shared_ptr<zs_argparser> make_parser(
        const std::string &help = "",
        const std::pair<std::string, std::string> &prefix = {"-", "--"});

    /**
     * @brief 添加一个参数
     *
     * @param opt 参数信息
     * @return true 添加成功
     * @return false 添加失败
     */
    bool add_argument(zs_argv_opt_t opt);

    /**
     * @brief 添加一个参数
     *
     * @param short_name 短名称
     * @param long_name 长名称
     * @param type 类型
     * @param required 是否必须
     * @param default_value 默认值
     * @param json_name json键名称
     * @param action 动作
     * @return true 添加成功
     * @return false 添加失败
     */
    bool add_argument(std::string short_name, std::string long_name,
                      zs_json_type type = zs_json_type::string,
                      bool required = true, zs_json default_value = zs_json(),
                      std::string json_name = "",
                      zs_argv_action action = zs_argv_action::store);

    /**
     * @brief 添加子解析器
     *
     * @param name 解析器名称（会被用于键名称）
     * @param sub_parser 子解析器
     */
    void add_sub_parser(const std::string &name,
                        std::shared_ptr<zs_argparser> sub_parser);

    /**
     * @brief 解析参数
     *
     * @param argc 参数数量
     * @param argv 参数列表
     * @param skip0 跳过参数0
     * @return zs_json 解析的参数对象（json格式）
     */
    zs_json parse_argv(int argc, const char **argv, bool skip0 = true) const;
};

}    // namespace zerone
