#pragma once

namespace uk { 

    express_tcp_t selector() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            cli.write( _STRING_(
                .uk-selector>label>input[type*="radio"] { 
                    display: none; 
                }
                .uk-selector>label:has(:checked) { 
                    border: 1px solid var(--neutral);
                    background-color: var(--neutral);
                    color: inherit;
                }
                .uk-selector>label { 
                    background-color: var(--none);
                    border: 1px solid var(--none);
                    text-transform: capitalize;
                    border-color: var(--none);
                    border-radius: 20px;
                    align-items: center;
                    text-align: center;
                    font-weight: 600;
                    cursor: pointer;
                    font-size: 16px;
                    color: inherit;
                    padding: 8px;
                }
            ));
            
            for( auto& color: map_t<string_t,string_t>({
                { "primary",   "light" },
                { "secondary", "light" },
                { "success",   "dark"  },
                { "warning",   "light" },
                { "danger",    "light" },
                { "mute",      "dark"  },
                { "dark",      "light" },
                { "light",     "dark"  },
                { "neutral",   "light" }
            }).data() ){ cli.write( regex::format( _STRING_(

                .uk-selector-${0}>label:has(:checked) { 
                    background-color: var(--${0});
                    border: 1px solid var(--none);
                    color: var(--${1});
                }
                .uk-selector-${0}>label { 
                    background-color: var(--${0});
                    border-color: var(--none);
                }

                .uk-selector-${0}-outline>label { 
                    background-color: rgba( from var(--${0}) r g b / 10% );
                    border: 1px solid var(--${0});
                    color: var(--${0});
                }
                .uk-selector-${0}-outline>label:has(:checked) { 
                    background-color: var(--${0});
                    border: 1px solid var(--none);
                    color: var(--${1});
                }

                .uk-selector-active-${0}-outline>label:has(:checked) { 
                    background-color: rgba( from var(--${0}) r g b / 10% ) !important;
                    border: 1px solid var(--${0}) !important;
                    color: var(--${0}) !important;
                }
                .uk-selector-active-${0}>label:has(:checked) { 
                    background-color: var(--${0}) !important;
                    border: 1px solid var(--none) !important;
                    color: var(--${1}) !important;
                }

            ), color.first, color.second )); }

        });

        return app;
    }

}